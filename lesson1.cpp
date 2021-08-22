// lesson1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using std::string;


class AbstractEmployee {
    //pure virtual func; must implement this method
    //virtual classes extend base class
    virtual void AskForPromotion()=0;
};



class Employee:AbstractEmployee {

private:
    string Name;
    string Company;
    int Age;
public:

    void setName(string name) {//setter
        Name = name;
    }
    string getName() {//getter
        return Name;
    }
     void setCompany(string company) {//setter
        Company=company;
    }
    string getCompany() {//getter
        return Company;
    }
    void setAge(int age) {//setter with qualifier
        if (age > 17) {
            Age = age;
        }
         
    }
    int getAge() {//getter
        return Age;
    }
         
    void IntroduceYourself() {
        std::cout << "Name -  " << Name << std::endl;
        std::cout << "Company -  " << Company << std::endl;
        std::cout << "Age -  " << Age<< std::endl<<"\n\n";
    }

    Employee(string name, string company, int age) {
        Name = name;
        Company = company;
        Age = age;
    }
    void AskForPromotion() {
//this is a method from our abstract class
        if (Age > 30)
            std::cout << Name << " got promoted " << std::endl;
        else 
            std::cout << "no promotion for you today, ha!" << std::endl << "\n\n";
    }
};

//let's make a constuctor so we don't have to use the cumbersome default constucto
//(1)consturctor must be pulblic & (2)must have name of class & (3) no return 


class Developer:Employee {
public:
    string FavProgrammingLanguage;
    //Developer needs a constructor (see line 68)
    Developer(string name, string company, int age, string language)
        :Employee(name, company, age)
    {
        FavProgrammingLanguage = language;
    }

    //Developer has one method
    void FixBug() {
        std::cout << getName() << " fixed a bug using " << FavProgrammingLanguage << "\n\n";
     }

};

int main()
{
    Employee employee1=Employee("Saldina", "CodeBeauty", 25);
    Employee employee2=Employee("Tyson", "CodeBeauty", 64);
    
    Developer d=Developer("Jordan", "Gun Store", 50, "C++");
    

    /*employee1.Name="Saldina"   ;
    employee1.Company="CodeBeauty"   ;
    employee1.Age=25  ;*/
    employee1.IntroduceYourself();

    /*employee2.Name="Tyson"   ;
    employee2.Company="CodeBeauty"   ;
    employee2.Age=64  ;*/
    employee2.IntroduceYourself();

    employee1.setAge(9);
//test our setters and getters
    std::cout << employee1.getName() << " is " << employee1.getAge() << "years old\n\n";

    employee1.AskForPromotion();
    employee2.AskForPromotion();
    d.FixBug();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
