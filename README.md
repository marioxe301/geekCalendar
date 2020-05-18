# Geek Calendar
![calendario](https://github.com/marioxe301/geekCalendar/blob/master/img/format.png)

### Solamente una aplicacion que te permite ver un calendario del mes actual en la terminal
## Para compilar
### * Se puede usar el makefile
> $ make
### **o**
> $ g++ main.cpp calendar.cpp -o gkcalendar

## Para Correrlo
### * Se puedo ejecutar sin parametros ( en este caso nos imprimiria el calendario con la fecha actual )
> $ ./gkcalendar
### * Se le puede mandar 2 parametros ( el primero el mes [ 0-11 ] y el segundo el año ) y les mostrara el calendario de ese mes en ese año
> $ ./gkcalendar 2 2000

## Para ejecutarlo de cualquier lado en terminal
### * Primero Compilarlo
### * Poner en cualquier carpeta el binario ( en este caso se creo una carpeta llamada mybins y ahi se metio el binario )
> $ cd /

> $ sudo mkdir mybins

> $ sudo mv < path del binario > < path de la carpeta >
### * Por ultimo ir a home y agregar al archivo .bashrc el path del binario
> export PATH=$PATH:< path de la carpeta del binario >
