//Objects combine individual data and functions
//A data element of an object is called a data member, while a function of an object is
//called a member function.
//As a concrete example, think about that alien
//spacecraft. An alien spacecraft object might be of a new type called Spacecraft,
//defined by a game programmer, and might have a data member for its energy
//level and a member function to fire its weapons
//In practice, an object’s energy
//level might be stored in its data member energy as an int, and its ability to fire
//its weapons might be defined in a member function called fireWeapons().

//The cool thing about objects is that you don’t need to know the implementation
//details to use them—just as you don’t need to know how to build a car in order
//to drive one. You only have to know the object’s data members and member
//functions—just as you only need to know where a car’s steering wheel, gas pedal,
//and brake pedal are located.
/*You can store objects in variables, just like with built-in types. Therefore, you
could store an alien spacecraft object in a variable of the Spacecraft type. You
can access data members and member functions using the member selection
operator (.), by placing the operator after the variable name of the object. So if
you want your alien spacecraft, ship, to fire its weapons only if its energy level is
greater than 10, you could write:
// ship is an object of Spacecraft type
if (ship.energy > 10)
{
ship.fireWeapons()
}
*/
//ship.energy accesses the object's energy data member, while ship.fireWeapons()
//calls the objects fireWeapons() member function

#include <iostream>

#include <string>

using namespace std;


int main()
{
    string word1 = "Game";
    string word2("Over");
    string word3(3, '!');

    string phrase = word1 + " " + word2 + word3;
    cout << "The phrase is:" << phrase << "\n\n";
    phrase[0] = 'L';
    cout << phrase << "\n\n";

    cout << "The character at position 0 is:" << phrase[0] << "\n\n";
    cout << "Phrase size is:" << phrase.size() << endl;

    for (int i = 0; i < phrase.size();++i)
    {
        cout << "Character at position" << i << "is:" << phrase[i] << endl;
    }

    cout << "The position of over inside Game Over:" << phrase.find("Over") << "\n\n";
    cout << "erased string:" << phrase.erase(3,5)<<endl;

    // phrase.erase();
    if (phrase.empty())
    {
        cout << "\nThe phrase is no more.\n";
    }
    else
    {
        cout << "Reggae is still on.\n";
    }
}

/*
Using the size() Member Function
Okay, it’s time to take a look at a string member function. Next, I use the
member function size():
cout << "The phrase has " << phrase.size() << " characters in it.\n\n";
phrase.size() calls the member function size() of the string object phrase
through the member selection operator . (the dot). The size() member
function simply returns an unsigned integer value of the size of the string
object—its number of characters. Because the string object is "Lame Over!!!",
the member function returns 12. (Every character counts, including spaces.)
Of course, calling size() for another string object might return a different
result based on the number of characters in the string object.
*/

/*
Indexing a string Object
A string object stores a sequence of char values. You can access any individual
char value by providing an index number with the subscripting operator ([]).
That’s what I do next:
cout << "The character at position 0 is: " << phrase[0] << "\n\n";
The first element in a sequence is at position 0. In the previous statement, phrase
[0] is the character G. And because counting begins at 0, the last character in the
string object is phrase[11], even though the string object has 12 characters
in it.

Not only can you access characters in a string object with the subscripting
operator, but you can also reassign them. That’s what I do next:
phrase[0] = ’L’;
I change the first character of phrase to the character L, which means phrase
becomes "Lame Over!!!"
*/

//Find member function
/*
Using the find() Member Function
Next I use the member function find() to check whether either of two string
literals are contained in phrase. First, I check for the string literal "Over":
cout << "\nThe sequence ’Over’ begins at location ";
cout << phrase.find("Over") << endl;
The find() member function searches the calling string object for the string
supplied as an argument. The member function returns the position number of
the first occurrence where the string object for which you are searching begins
in the calling string object. This means that phrase.find("Over") returns the
position number where the first occurrence of "Over" begins in phrase. Since
phrase is "Lame Over!!!", find() returns 5. (Remember, position numbers begin
at 0, so 5 means the sixth character.)
But what if the string for which you are searching doesn’t exist in the calling
string? I tackle that situation next:
if (phrase.find("eggplant") == string::npos)
{
cout << "’eggplant’ is not in the phrase.\n\n";
}
Because "eggplant" does not exist in phrase, find() returns a special constant
defined in the file string, which I access with string::npos. As a result, the
screen displays the message, “’eggplant’ is not in the phrase.”
The constant I access through string::npos represents the largest possible size
of a string object, so it is greater than any possible valid position number in a
string object. Informally, it means “a position number that can’t exist.” It’s
the perfect return value to indicate that one string couldn’t be found in
another.
*/

//Using the erase() Member Function
/*
The erase() member function removes a specified substring from a string
object. One way to call the member function is to specify the beginning position
and the length of the substring, as I did in this code:
phrase.erase(4, 5);
The previous line removes the five-character substring starting at position 4.
Because phrase is "Lame Over!!!", the member function removes the substring
Over and, as a result, phrase becomes "Lame!!!".
Another way to call erase() is to supply just the beginning position of the
substring. This removes all of the characters starting at that position number to
the end of the string object. That’s what I do next:
phrase.erase(4);
This line removes all of the characters of the string object starting at position 4.
Since phrase is "Lame!!!", the member function removes the substring !!! and,
as a result, phrase becomes "Lame".
Yet another way to call erase() is to supply no arguments, as I did in this code:
phrase.erase();
The previous line erases every character in phrase. As a result, phrase becomes
the empty string, which is equal to "".
*/

//Using the empty() Member Function
/*
The empty() member function returns a bool value—true if the string object is
empty and false otherwise. I use empty() in the following code:
if (phrase.empty())
{
cout << "\nThe phrase is no more.\n";
}
Because phrase is equal to the empty string, phrase().empty returns true, and
the screen displays the message, “The phrase is no more.”
*/
