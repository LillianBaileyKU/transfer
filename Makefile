all: lblab11eecs348

lblab11eecs348: lblab11eecs348.cpp
    g++ -Wall -Wextra -o lblab11eecs348 lblab11eecs348.cpp

clean:
    rm -f lblab11eecs348