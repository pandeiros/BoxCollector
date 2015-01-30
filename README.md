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
30-01-2015_23-16-22 | 100000     | default                      | default                      | FB              | 0.723     | 94.493  %   |
```

* Local results example file
```
### BOX COLLECTOR RESULTS ###

    >>> DATASET INFO <<<
DATE       | 30-01-2015_23-16-5
RECORDS    | 100
INPUT      | default

    >>> TEST <<<
ALGORITHM   | FB
HEURISTIC   | VOL
TIME        | 0.003000 [sec]
STACKS      | 25
TOTAL VOL.  | 178.687317
VOL. PROFIT | 53.783009 %


BOX ARRANGEMENT
======================================================================================
 ID          | LENGTH     | WIDTH      | HEIGHT     | VOLUME        | STD. DEVIATION |
======================================================================================
                                     Stack 0
--------------------------------------------------------------------------------------
          52 | 3.246      | 3.0752     | 2.4263     | 24.2196       | 0.432464       |
           6 | 2.9674     | 2.7354     | 2.272      | 18.4419       | 0.354057       |
          51 | 2.6325     | 2.5951     | 1.9968     | 13.6413       | 0.356716       |
```