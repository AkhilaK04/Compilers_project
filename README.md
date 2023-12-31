# phiC

**phiC** is a Domain-Specific Language (DSL) designed specifically for working with point masses within a two-dimensional plane, providing a comprehensive resource for understanding and applying key concepts in this domain. This DSL covers a range of essential topics in the kinematics of point masses in a concise and accessible manner and simplifies the process of solving problems related to motion, trajectory, collisions, and more.

## Features

- Basic equations of motion (velocity, distance, and acceleration).
- Projectile motion calculations (trajectory, range, time of flight, height, angle, and radius of curvature).
- Collision analysis, including inelastic and elastic collisions.
- Utilizes the coefficient of restitution and principles of linear momentum and energy conservation.
- Designed for working with point masses within a two-dimensional plane.


## Development Phases

### Phase I: Language Specification

In Phase I, we defined the language specification for our DSL. We created a formal [document](./Phase%20I/White_Paper_Compilers_Project.pdf) that outlines the expected behavior of the DSL, including the supported operations and input/output formats.


### Phase II: Lexer and Parser

Phase II focused on implementing the lexer and parser for **phiC**:

- Lexer: Responsible for tokenizing input, generates output file tokenfile.txt containing input tokens.
- Parser: Converts tokens into a parser tree, generating output file parsefile.txt containing parsed statements.

#### Installation Commands:

- To install lex (flex): `  sudo apt-get install flex`
- To install yacc (bison): `  sudo apt-get install bison`


### Phase III: Semantic Analysis

Phase III of the compiler includes semantic analysis. This phase ensures the correctnes of the all program statements and declarations. The evaluation of semantic rules involve inclusion of symbol table, execution of semantic checks and generation of error messages.

### Phase IV: Code Generation

Code generation, the fourth phase of compiler design, transforms the source code into correspondent cpp code that can be directly executed by the target system.

##  Team Members

• [Srinith Dasari](https://github.com/Srinith04)  
• [Santoshi Gayatri Mavuru](https://github.com/SantoshiGayatri)  
• [Pranav Varma Pericherla](https://github.com/Pranav-Varma-03)  
• [Akhila Kumbha](https://github.com/AkhilaK04) 

### Work Division and Team Meets Log
[LOG](https://docs.google.com/spreadsheets/d/1ETEy9Yb0NO1S7Q3EFXXnQJBY2lGCzA8NBun03dXzW8w/edit#gid=0)


