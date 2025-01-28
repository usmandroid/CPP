First Intro to Doxygen: https://youtu.be/pnnKzkNTo4w

Documentation for Getting started Doxygen Doxygen: [Getting started](https://www.doxygen.nl/manual/starting.html)

VS Code Extension: [Doxygen Documentation Generator - Visual Studio Marketplace](https://marketplace.visualstudio.com/items?itemName=cschlosser.doxdocgen)

```bash
​mkdir docs
cd docs/
# Initialize Doxygen for your repo
doxygen -g
# Creates `Doxyfile` configure it

# Set `USE_MDFILE_AS_MAINPAGE = ../README.md` in DoxyFile
# run doxygen command inside `doc` folder
doxygen
```