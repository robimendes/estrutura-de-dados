#include <stdexcept>
#include "../resources/test_base.h"
#include "../../main/2023/week_3/linked_stack/linked_stack.cpp"
#include <cstddef>

SCENARIO("Initializing a Stack structure") {
    GIVEN("an attempt to initialize a Stack") {
        Stack *stack = new Stack();

        WHEN("the stack was initialized") {
            THEN("stack should be empty") {
                CHECK(stack->isEmpty() == true);
            }
        }
    }
}

SCENARIO("Stack is empty") {
    GIVEN("an empty stack") {
        Stack linkedStack;
        
        WHEN("try to allocate a new element") {
            ItemType item = 'a';
            linkedStack.push(item);

            THEN("stack should not be empty anymore") {
                CHECK(linkedStack.isEmpty() == false);
            }   
        }

        WHEN("try to pop out an element") {
            THEN("it does nothing with the stack") {
                ItemType popped =  linkedStack.pop();

                CHECK(popped == NULL);
            }
        }

        WHEN("is called isEmpty() method")
        {
            THEN("it should return true")
            {
                CHECK(linkedStack.isEmpty() == true);
            }
        }
    }
}

SCENARIO("Stack has at least 1 element") {
    GIVEN("a stack with 1 element") {
        Stack linkedStack;
        linkedStack.push('a');
        
        WHEN("it is tried to allocate a new item") {
            THEN("it should allocate this new item successfully") {
                linkedStack.push('b');
                CHECK(linkedStack.isEmpty() == false);
            }

            AND_THEN("this new item should be allocated at the top of the stack") {
                linkedStack.push('b');
                ItemType top = linkedStack.pop();
                ItemType topPrevious = linkedStack.pop();
                ItemType empty = linkedStack.pop();

                CHECK(top == 'b');
                CHECK(topPrevious == 'a');
                CHECK(empty == NULL);
            }
        }
    
        AND_WHEN("it is tried to pop an item") {
            ItemType poppedItem = linkedStack.pop();
            
            THEN("it should return the popped item from the stack") {
                CHECK(poppedItem == 'a');
            }
        }
    }

    GIVEN("a stack with 2 elements") {
        Stack linkedStack;

        ItemType firstItem = 'a';
        ItemType secondItem = 'b';

        linkedStack.push(firstItem);
        linkedStack.push(secondItem);

        WHEN("it is tried to allocate a new item") {
            ItemType thirdItem = 'c';

            linkedStack.push(thirdItem);
            
            THEN("it should allocate this new item") {
                ItemType popped = linkedStack.pop();
                CHECK(popped == 'c');
            }
        }
        
        AND_WHEN("it is tried to pop an element") {
            int lastTopItem = secondItem;

            ItemType poppedItem = linkedStack.pop();
            
            THEN("it should return the popped item from the stack") {
                CHECK(poppedItem == lastTopItem);
            }

            AND_THEN("the element of the top should be the right before") {
                lastTopItem = firstItem;
                poppedItem = linkedStack.pop();
                CHECK(lastTopItem == poppedItem);
            }
        }
    }
}


/*
*   To test the given scenarios bellow it is needed more advanced features
*   like mocks (doubles, spies, etc) and once it is just for didatic rea-
*   sons I will not worry about it now.
*/

// SCENARIO("Stack is fullfilled") {
//     GIVEN("fullfilled stack") {

//         WHEN("isFull is called") {
//             THEN("it should be true") {
//                 CHECK(vectorStack.isFull() == true);
//             }
//         }

//         WHEN("it is tried to allocate a new item") {
//             THEN("it shouldn't allocate the new item") {
//                 CHECK(structure[topOfStack] == secondItem);
//             }
//         }
//     }
// }
