
main
        define a char(1)

        options
                prompt line last,
                message line last-1,
                comment line last

        open window w0 at 2,2 with 20 rows,60 columns attribute(border)

        display 'HELLO world' at 8,20 attribute(green)
        prompt 'Hit any key to open form ' for char a

        open window w1 at 2,2 with form 'helloFORM' attribute(border,yellow)
        sleep 3
        display 'anytext' to formonly.a
	display 'more text' at 1,10
        prompt 'Hit any key ' for char a
	close window w1
        close window w0

	end main
