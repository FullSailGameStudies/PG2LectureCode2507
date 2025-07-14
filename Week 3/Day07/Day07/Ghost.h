#pragma once
//must include the headers for the types used in THIS file
//ONLY #include headers that are needed here
#include <string>
#include "../../../Shared/Console/Console.h"
class Ghost
{
	//what can the class do? (methods)
	//what describes the objects of this class? (fields/variables)

	//access modifiers: (determines what other code can see)
	//public: ALL code can see it
	//private: ONLY this class can see it*
	//protected: (inheritance) only this class AND all descendents of this class
	//be a restrictive as possible (protect your class)
public:
	//getters/setters are usually public
	//   "OK" to put the definition w/ the declaration
	// 
	//getters (accessor)
	//  usually const methods
	//  return type matches the type of the field
	//  simply returns the field
	//  usually no parameters
	std::string GetName() const { return name_; } //compiler "might" inline these
	ConsoleColor Color() const { return color_; }

	//setters (mutators)
	//  no return type
	//  usually have 1 parameter to set the field with
	//  can't be const b/c they change the field
	//	good place to validate the incoming data
	void Color(ConsoleColor color)
	{
		if (color != ConsoleColor::Yellow)
		{
			color_ = color;
		}
	}
	void SetName(const std::string& name)
	{
		if (not name.empty() && name.size() < 12)
		{
			name_ = name;
		}
	}

	void WhoAmI();

	//constructors (ctor)
	// IF you do not write a ctor, 
	//		the compiler gives you a default ctor (no parameters)
	// the purpose of ctors is to initialize the object
	// IF you write a ctor, the compiler's default ctor is no longer available
	Ghost(const std::string& name, ConsoleColor clr);
protected:
private:
	//make the fields private most of the time
	//fields are the data of the class
	//naming conventions:
	//  _stricmp  stricmp  push_back  pushBack  PushBack
	// m_sName  m_name mName _name name_ 
	std::string name_;
	ConsoleColor color_;

	void Method(std::string name)
	{
		//std::string name;

		name_ = name;
	}

};

