 <p align="center">
<h1>First project SHELL</h1></p>

 <p>In our second project, one of the most important functions included in the standard library was created from scratch, very similar to that of printf called _printf.
Print format through standard output allows you to print special characters, strings, identifiers, integers and an infinity of tool that speeds up learning in the world of programming.</p>

<h3> Prototype<h3> 

```
int _printf(const char *format, ...);
```

<h3> Format Code:</h3>

| Type of character     | Expected value | Output format | 
| --------------------- | -------------- | ------------- |
| %c  | Character | Print single character |
| %s  | The direction of a string | Print string of characteres |
| %d  | Integer |Print decimal numbers|
| %i  | Integer  |Print integers |
| %%  | None  |  Print the character % | 


<h3> Instructions🚀 <h3> ok

<p>To download the program and run it first
they should follow these steps:</p>

<p>1. Have vagrant, wsl, visual studio code or a virtual machine.</p>

```
sudo apt-get install vagrant
```

<p>2. Install a text editor like emacs, vi or sublime text.</p>

```
sudo apt-get install emacs
```

<p>3. Install the Ubuntu 20.04 LTS compiler.</p>

```
sudo apt-get install gcc
```

<p>4. Clone the repository.</p>

```
git clone https://github.com/JessicaJulieth/printf.git
```

<p>5. All files must be compiled with.</p>

```
gcc -Wall -Wextra -Werror -pedantic -std = gnu89 -Wno-format * .c
```

<h3>The most beautiful part of the program 📑 <h3>

<p>When the .c files are compiled with the gcc program, an executable file called a.out is automatically generated, which must be executed with the following command:</p>

```
int main()
{_
_printf(_printf("String:[%s]\n", "I am a string !"));
return (0);
}
./out.c
String:[I am a string !]
```
```
int main()
{
_printf("Character:[%c]\n", 'H');
return (0);
}
./out.c
 Character:[H]
```

<h3> Example <h3> ok
<p>If the following commands are executed, the following results will be obtained</p>

```
./a.out
```


<h3> Files <h3> ok

| FILES | DESCRIPCION1 |
| ----- | ------------ |
| shell.c | Contain the function that produces output according to a format.
| getPhatc | Contain all the functions of each case |
| c.c | Contain the structure to the code |
| holberton.h | Contain all library that we used to call the functions |
| man_1_simple_shell | Contain the description to each function and comand |


<h3> Authors <h3> ok

<p>Dairo Julian Carlosama 3392@holbertonschool.com</p>
<p>Jessica Julieth Sanabria 3476@holbertonschool.com</p>

