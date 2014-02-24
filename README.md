xvg-interpreter
===============

Interpreter for xvg (Xml Vector Graphics) files.

Takes XVG (Minimal version of <a href="http://en.wikipedia.org/wiki/Scalable_Vector_Graphics" target="_blank">SVG</a>) file as a input and generates graphics in a separate window.

Please look into `/examples/` to see some example of xvg files.

Run it as : ```./xvg-interp <path to XVG file as input>```


===============
<h2>Requirement:</h2>

<b>Windows</b>:
  No extra requirement for windows system as they have DOS graphics support.
  
<b>Ubuntu</b> :
  Needs `libgraph1.2.0` or higher.


================
<h2>Examples</h2>

Here some examples are given with their respective screenshots.

```shell
./xvg-interp ../examples/cartoon.xvg
```
![Alt text](/screenshots/1.png "./xvg-interp ../examples/cartoon.xvg")


```shell
./xvg-interp ../examples/rangoli.xvg
```
![Alt text](/screenshots/2.png "./xvg-interp ../examples/rangoli.xvg")


```shell
./xvg-interp ../examples/ellipseArt.xvg
```
![Alt text](/screenshots/3.png "./xvg-interp ../examples/ellipseArt.xvg")