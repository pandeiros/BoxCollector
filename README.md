# BoxCollector
####Author
* **Paweł Kaczyński**
* Warsaw University of Technology
* Faculty of Electronics and Information Technology

####Problem
Ortodoksyjny kolekcjoner tekturowych kartonów zaczyna narzekać na brak
miejsca do przechowywania swoich cennych zdobyczy. Postanowił
oszczędzić miejsce przez wkładanie kartonów jeden w drugi. W trosce o
zachowanie dobrego stanu kartonów, umieszcza tylko jeden karton
wewnątrz większego, a wolną przestrzeń wypełnia materiałem ochronnym.
Tak zabezpieczony karton może następnie umieścić wewnątrz innego
większego kartonu, ale nie może umieścić dwóch kartonów obok siebie w
jednym kartonie. Dla danego zbioru kartonów należy znaleźć najlepsze
upakowanie kartonów, tzn. takie, które zwalnia najwięcej miejsca.

#### Program input
* `-h | --help` : Prints useful information about program.
* `-u | --usage` : Prints message with possible input parameters.
* `-f | --file [filename]` : Input file with information about boxes (*look below at "Input file"*)
* `-o | --output [filename]` : Output file to be created with program results.
* `--generate-tests [number_of_boxes]` : Forces program to generate its own tests in given number.
* `--algorithm [VOLUME | ]` : Specifies which algorithm to use. If not specified, program will use the best one.

#### Project files
* classes folder : Contains or project classes.
* data folder : Contains test files.
* tests folder : Contains results filed.

#### Project classes
* Program
    * Collection
        * Box
        * BoxArrangement
    * InputManager
    * OutputManager
    * Interface
* Utilities
* MessageHandler


#### Input file
* Each line represents a single box with 3 parameters: length, width and height.
* Each value is separated by space.
* Lines starting with '#' will be ignored (has to be first character in a line)
* Example:
```
# Ignored line
1.11 2.54 3.54
```

#### Output file
* Global results example row
```
2015-01-23 17:27:44 | 4          | ./data/data.txt              | ./tests/results.txt          | VOLUME          | 1.332 |
```

* Local results example file
```
### BOX COLLECTOR RESULTS ###

    >>> DATASET INFO <<<
DATE       | - 
RECORDS    | 4
INPUT      | ./data/data.txt

    >>> TEST <<<
ALGORITHM  | -
TIME       | 0.000000 [sec]
STACKS     | 3
TOTAL VOL. | 27.980675


BOX ARRANGEMENT
=====================================================================
 ID          | LENGTH     | WIDTH      | HEIGHT     | VOLUME        |
=====================================================================
                             Stack 0
---------------------------------------------------------------------
           2 | 2          | 5          | 1          | 10            |

                             Stack 1
---------------------------------------------------------------------
           0 | 2.54       | 3.54       | 1.11       | 9.98068       |
           3 | 1          | 1          | 1          | 1             |

                             Stack 2
---------------------------------------------------------------------
           1 | 2          | 2          | 2          | 8             |
```

#### Algorithms and structures
* VOLUME based algorithm : Sort boxes based on their volume and creates box stacks starting from the biggest and trying to fit next boxes inside previously created stacks or create new one.
