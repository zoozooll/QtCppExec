#include "json_exercise2.h"

#include <string>
#include <vector>
#include <nlohmann/json.hpp>
#include <iostream>

struct Hobby {
    std::string name;
    int frequency; // how often the person engages in this hobby per week

    // Define to_json function for Hobby
    friend void to_json(nlohmann::json& j, const Hobby& h) {
        j = nlohmann::json{{"name", h.name}, {"frequency", h.frequency}};
    }

    friend void from_json(const nlohmann::json& j, Hobby& p) {
        j.at("name").get_to(p.name);
        j.at("frequency").get_to(p.frequency);

    }
};

struct Person {
    std::string name;
    int age;
    std::vector<Hobby> hobbies;

    // Define to_json function for Person
    friend void to_json(nlohmann::json& j, const Person& p) {
        j = nlohmann::json{{"name", p.name}, {"age", p.age}, {"hobbies", p.hobbies}};
    }

    friend void from_json(const nlohmann::json& j, Person& p) {
        j.at("name").get_to(p.name);
        j.at("age").get_to(p.age);
        j.at("hobbies").get_to(p.hobbies);
    }
};


int json_exercise2_run()
{

    Hobby reading = {"reading", 7};
    Hobby hiking = {"hiking", 3};
    Hobby coding = {"coding", 5};

    Person person;// = {"John Doe", 30, {reading, hiking, coding}};
    person.name = "John Doe";
    person.age = 30;
    person.hobbies.push_back(reading);
    person.hobbies.push_back(hiking);
    person.hobbies.push_back(coding);
    // Convert the person object to JSON
    nlohmann::json json_person = person;

    // Output the JSON
//    std::cout << json_person.dump(4) << std::endl;


    // Convert the JSON back to a Person object
   Person new_person = json_person.get<Person>();

   // Output the new Person object details
   std::cout << "Name: " << new_person.name << "\nAge: " << new_person.age << "\nHobbies:\n";
   for (const auto& hobby : new_person.hobbies) {
       std::cout << "  " << hobby.name << " (" << hobby.frequency << " times per week)\n";
   }
   std::cout << std::endl;

    return 0;
}
