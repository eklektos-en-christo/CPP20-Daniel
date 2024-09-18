//
// Created by Εκλεκτός εν Χριστώ on 9/12/24.
//

// global module fragment
// necessay to include all the headers and user defined headers
module;

//#include <iostream>


// necessary to export the module with name, this name is used to import the modules in other files
export module math;

// import another module and exports it from this module - submodule
export import math.div;

// import the partition of this module and export it to the importers
export import :multiply;



// module preamble - to import other modules here, C style headers are not allowed
// import <string>;    // C++ headers can also be imported here




// module purview starts here - all the module content we want to use in other files
// export block - we can put all the stuff here with specifying each item with export
export
{
    int add(int x, int y);
}