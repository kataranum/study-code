#include "bugHunt_assistance_system.hpp"
#include <iostream>

DistanceSensor::DistanceSensor(const std::string &sensor_position,
                               double initial_distance_m)
    : position(sensor_position),
      active(true),
      measured_distance_m(initial_distance_m)
{
}

void DistanceSensor::set_distance(double distance_m)
{
    measured_distance_m = distance_m;
}

void DistanceSensor::activate()
{
    active = true;
}

void DistanceSensor::deactivate()
{
    active = false;
}

double DistanceSensor::get_distance() const
{
    return measured_distance_m;
}

bool DistanceSensor::is_active() const
{
    return active;
}

// Fix 4: String const reference to avoid expensive copy
const std::string& DistanceSensor::get_position() const
{
    return position;
}

bool DistanceSensor::operator<(const DistanceSensor &other) const
{
    // Fix 5: Correct comparison
    return measured_distance_m < other.measured_distance_m;
}

bool DistanceSensor::is_exactly_at_warning_distance(double warning_distance) const
{
    // Fix 6: Use approximation because float equality is unreliable
    constexpr double EPSILON = 0.000001;

    double delta = std::abs(measured_distance_m - warning_distance);

    return delta < EPSILON;
}

void DistanceSensor::print_info() const
{
    std::cout << "Sensor position: " << position << '\n';
    std::cout << "Distance: " << measured_distance_m << " m\n";
    std::cout << "Active: " << std::boolalpha << active << "\n\n";
}

EmergencyBrakeSystem::EmergencyBrakeSystem(double critical_distance)
    : critical_distance_m(critical_distance)
{
}

void EmergencyBrakeSystem::evaluate(Vehicle &vehicle,
                                    const DistanceSensor &front_sensor) const
{
    if (!front_sensor.is_active())
    {
        return;
    }

    // Fix 5: Correct comparison
    if (front_sensor.get_distance() < critical_distance_m)
    {
        std::cout << "[EmergencyBrakeSystem] Emergency braking triggered.\n";
        vehicle.brake(30.0);
    }
}

LaneKeepingAssist::LaneKeepingAssist(double max_offset,
                                     double correction)
    : max_allowed_offset_m(max_offset),
      correction_angle(correction)
{
}

void LaneKeepingAssist::evaluate(Vehicle &vehicle) const
{
    double offset = vehicle.get_lane_offset();

    if (offset > max_allowed_offset_m)
    {
        std::cout << "[LaneKeepingAssist] Correcting to the left.\n";
        vehicle.steer(-correction_angle);
    }
    else if (offset < -max_allowed_offset_m)
    {
        std::cout << "[LaneKeepingAssist] Correcting to the right.\n";
        vehicle.steer(correction_angle);
    }
    else
    {
        vehicle.steer(0.0);
    }
}

AdaptiveCruiseControl::AdaptiveCruiseControl(double target_speed,
                                             double minimum_distance)
    : target_speed_kmh(target_speed),
      minimum_distance_m(minimum_distance)
{
}

void AdaptiveCruiseControl::evaluate(Vehicle &vehicle,
                                     const DistanceSensor &front_sensor) const
{
    if (!front_sensor.is_active())
    {
        return;
    }

    if (front_sensor.get_distance() < minimum_distance_m)
    {
        // Fix 9: Brake when too close
        std::cout << "[AdaptiveCruiseControl] Vehicle ahead is close. Braking.\n";
        vehicle.brake(5.0);
    }
    else if (vehicle.get_speed() < target_speed_kmh)
    {
        std::cout << "[AdaptiveCruiseControl] Increasing speed.\n";
        vehicle.accelerate(5.0);
    }
    else if (vehicle.get_speed() > target_speed_kmh)
    {
        std::cout << "[AdaptiveCruiseControl] Reducing speed.\n";
        vehicle.brake(5.0);
    }
}

ParkingAssistant::ParkingAssistant(double warning_distance)
    : warning_distance_m(warning_distance)
{
}

void ParkingAssistant::add_sensor(std::shared_ptr<DistanceSensor> sensor)
{
    sensors.push_back(sensor);
}

void ParkingAssistant::print_warnings() const
{
    for (std::shared_ptr<DistanceSensor> sensor : sensors)
    {
        if (sensor != nullptr &&
            sensor->is_active() &&
            sensor->get_distance() < warning_distance_m)
        {
            std::cout << "[ParkingAssistant] Warning at "
                      << sensor->get_position()
                      << ": obstacle detected.\n";
        }
    }
}