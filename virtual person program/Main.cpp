/*
Name: Hisham Odeh
Date: 4/21/2022
Program: virtual person program
*/

#include <iostream>
#include <vector>
#include <limits>
class Person
{
	private:
		std::string firstName;
		std::string lastName;
		std::string address;
		std::string zipCode;
		std::string phoneNumber;
		
	public:
		//--------getters----------//
		std::string getFirstName(){return firstName;}
		std::string getLastName(){return lastName;}
		std::string getAddress(){return address;}
		std::string getZipCode(){return zipCode;}
		std::string getPhoneNumber(){return phoneNumber;}
		
		//---------setters---------//
		void setFirstName(std::string firstName){this->firstName = firstName;}
		void setLastName(std::string lastName){this->lastName = lastName;}
		void setAddress(std::string address){this->address = address;}
		void setZipCode(std::string zipCode){this->zipCode = zipCode;}
		void setPhoneNumber(std::string phoneNumber){this->phoneNumber = phoneNumber;}

		virtual void displayPersonInfo()
		{
			std::cout<<"\n--------Person----------------\n";

			std::cout<<"First name:\t"<<firstName<<" /LastName\t"<<lastName;
			std::cout<<" /Adress:\t"<<address<<" /Zip code:\t"<<zipCode<<" /Phone number:\t"<<phoneNumber<<std::endl;
		}
};

class Employee : public Person
{
	private:
		std::string ssn;
		std::string departmentName;
	public:
		//--------getters----------//
		std::string getSsn(){ return ssn;}
		std::string getDepartmentName(){return departmentName;}
		
		//---------setters---------//
		void setSsn(std::string snn){this->ssn = snn;}
		void setDepartmentName(std::string departmentName){ this->departmentName =departmentName;}
		
		void displayPersonInfo()
		{
			std::cout<<"\n--------Employee----------------\n";
			std::cout<<"First name:\t"<<getFirstName()<<" /LastName\t"<<getLastName();
			std::cout<<" /Adress:\t"<<getAddress()<<" /Zip code:\t"<<getZipCode()<<" /Phone number:\t"<<getPhoneNumber()<<std::endl;
			std::cout<<" /SSN:\t"<<ssn<<" /Department name:\t"<<departmentName<<std::endl;
		}
};
class Customer : public Person
{
	
	private:
		double discoutPercentage;
		std::string email;
	public:	
		//------getterrs--------//
		double getDiscount (){return discoutPercentage;}
		std::string getEmail(){return email;}
		
		//---------setters---------//
		void setDiscount(double discoutPercentage){this->discoutPercentage = discoutPercentage;}
		void setEmail(std::string email){this->email = email;}
		
		void displayPersonInfo()
		{
			std::cout<<"\n--------Customer----------------\n";
			std::cout<<"First name:\t"<<getFirstName()<<"/LastName\t"<<getLastName();
			std::cout<<"/Adress:\t"<<getAddress()<<"/Zip code:\t"<<getZipCode()<<"/Phone number:\t"<<getPhoneNumber();
			std::cout<<"/Discount percentage:\t"<<discoutPercentage<<"/Email:\t"<<email<<std::endl;
		}
		
	
};

void displayPerson(Person *person);
void validateNumaricData(int &choice, int min, int max);
void validateNumaricData(double &choice, int min, int max);

int main(){
	
	int choice = 0;
	std::string firstName;
	std::string lastName;
	std::string address;
	std::string zipCode;
	std::string phoneNumber;
	
	Person * aPerson = new Person;
	Employee * anEmployee = new Employee;
	Customer * aCustomer = new Customer;

	std::vector <Person * > people ;

	while (choice != 3){

		std::cout<<"Whould you like to\n1-Add an employee\n2-Add a Customer\n3-Quit\nChoice:\t";
		std::cin>>choice;
		validateNumaricData(choice, 1, 3);
		std::cin.ignore();
		
		if (choice == 1){
			
			std::cout<<"Enter the following information:"<<std::endl;		
			std::cout<<"\nFirst Name:\t";
			getline(std::cin ,firstName);
			anEmployee->setFirstName(firstName);
					
			std::cout<<"\nLast Name:\t";
			getline(std::cin ,lastName);
			anEmployee->setLastName(lastName);
	
			std::cout<<"\nAdress:\t";
			getline(std::cin ,address);
			anEmployee->setAddress(address);
					
			std::cout<<"\nZip Code:\t";
			getline(std::cin ,zipCode);
			anEmployee->setZipCode(zipCode);
					
			std::cout<<"\nPhone number:\t";
			getline(std::cin ,phoneNumber);
			anEmployee->setPhoneNumber(phoneNumber);


			std::string ssn;
			std::string departmentName;
			
			std::cout<<"\nSocial Security number:\t";
			getline(std::cin,ssn);
			anEmployee->setSsn(ssn);
			
			std::cout<<"\nDepartment Name:\t";
			getline(std::cin, departmentName);
			anEmployee->setDepartmentName(departmentName);
			
			aPerson = anEmployee;
			people.push_back(aPerson);
		}
		else if (choice ==2){
			std::cout<<"Enter the following information:"<<std::endl;		
			std::cout<<"\nFirst Name:\t";
			getline(std::cin ,firstName);
			aCustomer->setFirstName(firstName);
					
			std::cout<<"\nLast Name:\t";
			getline(std::cin ,lastName);
			aCustomer->setLastName(lastName);
	
			std::cout<<"\nAdress:\t";
			getline(std::cin ,address);
			aCustomer->setAddress(address);
					
			std::cout<<"\nZip Code:\t";
			getline(std::cin ,zipCode);
			aCustomer->setZipCode(zipCode);
					
			std::cout<<"\nPhone number:\t";
			getline(std::cin ,phoneNumber);
			aCustomer->setPhoneNumber(phoneNumber);
			
			double discoutPercentage;
			std::string email;
			
			std::cout<<"\nDiscount percentage:\t";
			std::cin>>discoutPercentage;
			validateNumaricData(discoutPercentage, 0, 100);
			aCustomer->setDiscount(discoutPercentage);
			std::cin.ignore();
			
			std::cout<<"\nEmail:\t"<<email;
			getline(std::cin, email);
			aCustomer->setEmail(email);
				
			aPerson = aCustomer;
			people.push_back(aPerson);
		}				

	}
	std::cout<<"\nQuiting......";

	for (Person * aPerson : people)
	{
		displayPerson(aPerson);
	}
	
	delete aPerson;
	delete anEmployee;
	delete aCustomer;
	return 0;
}

void displayPerson(Person *person)
{
	person->displayPersonInfo();
}
void validateNumaricData(int &choice, int min, int max)
{
	while(std::cin.fail()){
		
			std::cout<<"\nERROR:\tInvalid input Due to the wrong Data type, try again \nChoice:\t";
	  		std::cin.clear();
	   		std::cin.ignore( std::numeric_limits<std::streamsize>::max(),'\n'); 
	   		std::cin>>choice;
	}
	while ( choice > max || choice < min)
	{
		std::cout<<"\nERROR:\tOption selected is not valid, try again.\nChoice:\t";
		std::cin>>choice;
		validateNumaricData( choice,  min,  max);
	}
}
void validateNumaricData(double &choice, int min, int max)
{
	while(std::cin.fail()){
		
			std::cout<<"\nERROR:\tInvalid input Due to the wrong Data type, try again \nChoice:\t";
	  		std::cin.clear();
	   		std::cin.ignore( std::numeric_limits<std::streamsize>::max(),'\n'); 
	   		std::cin>>choice;
	}
	while ( choice > max || choice < min)
	{
		std::cout<<"\nERROR:\tOption selected is not valid, try again.\nChoice:\t";
		std::cin>>choice;
		validateNumaricData( choice,  min,  max);
	}
}


