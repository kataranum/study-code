# Justification for Section I UML diagram relations

**Course** and **Lesson** are connected via composition because **Lesson**
cannot exist without a **Course**. But a **Course** can have a total of 0
lessons, hence the asterisk for multiplicity.

**Course** and **User** are connected via Association because both are seperate
concepts and can exist independent of each other.
