
Images
Right - to get images to display - they need to be loaded from a 'resource'
...
 To do this - you need to create a directory
'Resources' - with some subdirectories..
 If you start the application - you should find that
the visual studio will start an ASP.NET server for you
 that should start in the taskbar
 If you right click on that - you should get a menu,
select "Show Details" - or the equivilent in Portuguese ;)
 That should give you a 'physical path'...
 On mine - its w:\aubitdesktopweb\
 Now - under w:\aubitdesktopweb\ you need to create
Resources
 And in that resources - you should create a directory
"icons" and a directory "images"
 Then in that images directory - put in any images you
need...
 In the 4tb file - you need to change the way you point
to the image so it says something like :
 <ToolBarItem name="INTERRUPT" text="Cancel"
image="Images.cancel.png"  />
 So - you give the full name of the image - and the
directory (Images) - and it uses a '.' as a separator - *NOT* a '/' or '\'
....
