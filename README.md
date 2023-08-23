<h1 align="center" style="font-size: 32px;"> MACROMEDIA JSFL Deobfuscator </h1>

### MACROMEDIA JSFL Deobfuscator or MJD is a small dynamic library for Adobe Animate that decodes obfuscated JSFL files into readable and editable JSFL files in any IDE
<strong> This library works only on Adobe Animate 22.0.3 on Windows system. If you need support for another version open a new issue</strong>

## How to use
Download dll file from releases and put it in the folder: ```C:\Users\{USER NAME}\AppData\Local\Adobe\Animate {VERSION}\{PROGRAM LANGUAGE CODE}\Configuration\External Libraries```  
After that, run one of jsfl scripts in "jsfl" folder.
You can decode whole folder or just one file as you wish.

## A little about file structure
Obfuscated jsfl files have a header of 16 bytes: ```00MACROMEDIAOBFU``` or hex ```00 00 4D 41 43 52 4F 4D 45 44 49 41 4F 42 46 55```   
After that comes 1 byte which probably means the version of the file. Usually equal to 1   
Everything after that is encrypted with "DES / EBC / pcks5 padding"  
It is very likely that algorithm may differ from original implementations and ideas. After several attempts to repeat code using public libraries and code implementations, I did not manage to get desired result, maybe I just tried badly.  

DES key for Animate 22.0.3: ```25 40 76 75 34 92 C4 40```

## JSAPI
I heavily modified mm_jsapi.h, which at least works, unlike what Adobe provides.  
I'm not sure if all the "JS_*" functions work correctly, but at least the most needed ones work for sure.  
Funny thing is, Adobe Animate actually provides a lot more features in mm_env, but these new features are not documented anywhere, thanks again to Adobe for being indifferent.