#ifndef FOOTBALL_MANAGER_HPP
#define FOOTBALL_MANAGER_HPP

#include <string>

class Player
{
private:
    std::string name;
    int age;

public:
    Player(const std::string &name, int age);
    virtual ~Player() = default;

    std::string get_name() const;
    int get_age() const;

    virtual void train(int intensity);
};

class InjuredPlayer : public Player
{
public:
    InjuredPlayer(const std::string &name, int age);

    void train(int intensity) override;
};

// VIOLATION of interface segregation (I)
// Child classes are forced to implement all functions even though they are for
// different purposes
class ClubService
{
public:
    virtual ~ClubService() = default;

    virtual void train_player(Player &player, int intensity) = 0;
    virtual void save_player(const Player &player) = 0;
    virtual void notify_player(const Player &player, const std::string &message) = 0;
};

class FilePlayerRepository
{
public:
    void save(const Player &player);
};

class EmailNotifier
{
public:
    void send(const Player &player, const std::string &message);
};

// VIOLATION of Single Responsibility
// FootballManager does all kinds of stuff with player, should be seperated
class FootballManager : public ClubService
{
private:
    void select_strategy(const std::string &strategy);

    // VIOLATION of DIP
    // dependencies should be abstract
    FilePlayerRepository repository;
    EmailNotifier notifier;

public:
    FootballManager() = default;

    void prepare_player(Player &player, const std::string &strategy);

    void train_player(Player &player, int intensity) override;
    void save_player(const Player &player) override;
    void notify_player(const Player &player, const std::string &message) override;
};

#endif
