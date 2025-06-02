/*
Examining Element Insertion and Deletion
Adding or removing an element from the end of a vector using the push_back()
or pop_back() member functions is extremely efficient. However, adding or
removing an element at any other point in a vector (for example, using insert()
or erase()) can require more work because you might have to move multiple
elements to accommodate the insertion or deletion. With small vectors the
overhead is usually insignificant, but with larger vectors (with, say, thousands of
elements), inserting or erasing elements from the middle of a vector can cause a
performance hit.
Fortunately, the STL offers another sequence container type, list, which allows
for efficient insertion and deletion regardless of the sequence size. The important
thing to remember is that one container type isn’t the solution for every problem.
Although vector is versatile and perhaps the most popular STL container type,
there are times when another container type might make more sense.
*/

/*
Just because you want to insert or delete elements from the middle of a sequence, that doesn’t
mean you should abandon the vector. It might still be a good choice for your game program. It
really depends on how you use the sequence. If your sequence is small or there are only a few
insertion and deletions, then a vector might still be your best bet.

*/