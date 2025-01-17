#include <stdexcept>
#include "../resources/test_base.h"
#include "../../main/2023/week_2/stack/vector_stack/vector_stack.cpp"
#include <cstddef>

bool isStackEmpty(ItemType *structure) {
    bool isEmpty = true;
    char empty = (char) NULL;

    for (int i = 0; i < 10; i++) {
        if (structure[i] != empty)
            isEmpty = false;
    }

    return isEmpty;
}

int CAPACITY = 10;

SCENARIO("Initializing a Stack structure") {
    GIVEN("an attempt to initialize a Stack") {
        
        ItemType structure[CAPACITY];
        VectorStack VectorStack(structure, CAPACITY);

        WHEN("the stack was initialized") {
            THEN("stack should be empty") {
                CHECK(isStackEmpty(structure) == true);
            }
        }
    }
}

SCENARIO("Stack is empty") {
    GIVEN("an empty stack") {
        int capacity = 100;
        ItemType *structure = new ItemType[CAPACITY];
        VectorStack vectorStack(structure, CAPACITY);
        
        WHEN("it is tried to allocate a new element") {
            ItemType item = 'a';
            vectorStack.push(item);

            THEN("it should allocate the new element successfully") {
                CHECK(structure[0] == item);
            }   
        }

        WHEN("it tries to pop out an element") {
            THEN("it does nothing with the stack") {
                try {
                    vectorStack.pop();
                }
                catch(std::exception e) {
                    CHECK(structure[0] == (char) NULL);
                }
            }

            AND_THEN("it should throw an exception") {
                CHECK_THROWS_AS(vectorStack.pop(), std::exception);
            }
        }

        WHEN("is called isEmpty() method")
        {
            THEN("it should return true")
            {
                CHECK(vectorStack.isEmpty() == true);
            }
        }
    }
}

SCENARIO("Stack has at least 1 element") {
    GIVEN("a stack with 1 element") {
        ItemType structure[CAPACITY];
        VectorStack vectorStack(structure, CAPACITY);
        vectorStack.push('a');
        
        WHEN("it is tried to allocate a new item") {
            THEN("it should allocate this new item successfully") {
                vectorStack.push('b');
                CHECK(structure[1] == 'b');
            }

            AND_THEN("this new item should be allocated at the top of the stack") {
                vectorStack.push('b');
                CHECK(structure[0] == 'a');
                CHECK(structure[1] == 'b');
                CHECK(structure[2] == (ItemType) NULL);
            }
        }
    
        AND_WHEN("it is tried to pop an item") {
            ItemType poppedItem = vectorStack.pop();
            
            THEN("it should return the popped item from the stack") {
                CHECK(poppedItem == 'a');
            }

            AND_THEN("should put a null in place of the popped value") {
                CHECK(structure[0] == (char) NULL);
            }

            AND_WHEN("it is tried to push a new item") {
                ItemType newItem = 'c';
                vectorStack.push(newItem);

                THEN("it should put this item in the bottom of the stack") {
                    int top = 0;

                    CHECK(structure[top] == newItem);
                }
            }
        }
    }

    GIVEN("a stack with 2 elements") {
        ItemType structure[CAPACITY];

        VectorStack vectorStack(structure, CAPACITY);

        ItemType firstItem = 'a';
        ItemType secondItem = 'b';

        vectorStack.push(firstItem);
        vectorStack.push(secondItem);

        WHEN("it is tried to allocate a new item") {
            ItemType thirdItem = 'c';

            vectorStack.push(thirdItem);
            
            THEN("it should allocate this new item") {
                CHECK(structure[2] == 'c');
            }

            AND_THEN("should allocate the new item at the top") {
                int top = 2;

                CHECK(structure[1] == 'b');
                CHECK(structure[top] == 'c');
                CHECK(structure[3] == (char) NULL);
            }
        }
        
        AND_WHEN("it is tried to pop an element") {
            int lastTopItem = secondItem;

            ItemType poppedItem = vectorStack.pop();
            
            THEN("it should return the popped item from the stack") {
                CHECK(poppedItem == lastTopItem);
            }

            AND_THEN("the element of the top should be the right before") {
                CHECK(structure[0] == firstItem);
                CHECK(structure[1] == (char) NULL);
            }
        }
    }
}

SCENARIO("Stack is fullfilled") {
    GIVEN("fullfilled stack") {
        int structureSize = 2;

        ItemType structure[structureSize];

        VectorStack vectorStack(structure, structureSize);

        ItemType firstItem = 'a';
        ItemType secondItem = 'b';

        vectorStack.push(firstItem);
        vectorStack.push(secondItem);

        WHEN("isFull is called") {
            THEN("it should be true") {
                CHECK(vectorStack.isFull() == true);
            }
        }

        WHEN("it is tried to allocate a new item") {
            ItemType thirdItem = 'c';
            int topOfStack = 1;

            vectorStack.push(thirdItem);

            THEN("it shouldn't allocate the new item") {
                CHECK(structure[topOfStack] == secondItem);
            }
        }
    }
}
