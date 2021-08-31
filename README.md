# setExpS_V
Alt  for funkySetFields-swak4Foam with easy setup for setting initial Scalar or Vector fields using a math expression. 
./setExpS ./setExpV


[INTRODUCTION]
C++ program to set initial fields of an OpenFOAM scalar or 
vector using a math-expression, taking co-ordinates as 
parameter. The expressions are based off of exprtk library 
by Arash Partrow. Check the link beneath for more info. 
readme.txt file describess expression syntax and involves 
exhaustive mathematical manipulation. 
https://github.com/ArashPartow/exprtk

This is an alternative to funkySetFields {swak4Foam) or 
setFields, for those who couldn't get them to work on their 
OpenFoam version. 
I couldn't get it to work on OF-8, but I won't take credit 
away from multiple versions & environments it's working on 
already. Minimum effort on getting it to work .
Simple Scalar Vector Formulation. 
Make good use of this quick fix. 

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

An exemplary testCase folder for scalarTransportFoam can 
be found in the repository, with custom ./Allclean & ./Allrun 
scripts. 
*Check below for more info*

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


./setExpS modifies scalar field using expressionS file both 
to be put in 0 folder. 

./setExpV modifies vector field using expressionV file both 
to be put in 0 folder. 



writeCellCentres function needs to be run before, as the  
executables require C file. It can be run non-destructively  
with:
postProcess -func writeCellCentres 

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

<Executaion>
./setExpS & ./setExpV modifies "Field" file to "Field.org"  
file & sets values w.r.t math expression, provided in  
expressionS & expressionV file. 

./setExpS asks to choose Scalar.
./setExpV asks to choose Vector.  

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

A modified ./Allrun & ./Allclean script is provided with  
the test case. This takes care of writing cell coordinates  
with writeCellCentres & modifies 0 folder to it's original  
form. 

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Source File setExpS.cpp, setExpV.cpp & header file 
exprtk.hpp files are provided in the repository for further 
compilation. 
