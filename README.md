# C-ToolBox
the c-toolbox is a repo containing a bunsh of ready to use tools for c programmers, it can be used as a building blocs or glew to all kinds of projects.

## Content

1. Math
    1. linear algibra
    1. geomitry
1. Collections
    1. dynamic array
    1. lists
    1. trees
1. String
1. IO
    1. file loader
    
## Design Concept Principles
1. Each functionality should be summed in a max of two files, a header file (.h) and a source file (.c).
2. Each header file should be layed out as follows : 
    1. Includes section
    2. Defines section
    3. Functions' signature diclaration section
3. Each functionality should be independent of any other functionality except for c standard libraries.
4. For each functionality under './src/' there is a test script under './tests/' that has the same relative path and name.  