##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## make build
##

SRC	=	*.c

NAME	=	my_runner

ERROR = -W -Wall -Wextra

SFML = -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system -lcsfml-network

all:
	gcc -o $(NAME) $(SRC) $(SFML) $(ERROR) -lm -Wno-unused-value
clean:
	rm -f $(CRITO) $(CRITA) unit-tests

fclean:
	rm -f $(NAME)

re:	fclean all

tests_run:
	gcc -o unit-tests ./lib/my/*.c ./tests/*.c $(SRC) -lcriterion --coverage
	./unit-tests
