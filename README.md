Init Mini_env (en cas d'unset de env) : A priori OK, non teste
Init Normal env : TO DO

Ft_CD : On ne peut pas compiler avec ft_cd parce qu'on n'a pas a fonction qui permet de chercher dans la liste t_env la valeur rangee a KEY dont nous avons besoin, dans ce cas la HOME. TO DO, mais ca ira.

Appel Exec : OK

Gestion des frees : A priori le free de t_env et t_env_links vont faire chier. TO DO.

Pipes : TO DO
Heredocs : TO DO
Redirs : TO DO
Builtins en processus parent (IMPORTANT POUR CD, UNSET, EXPORT, etc) : TO DO


TESTS BUILTINS :
[regler le dernier \n en trop. ]
Ft_env : A priori OK
Ft_echo : A priori, OK
Ft_pwd : A priori OK
Ft_exit ; A priori OK
unset :  marche pas
export : SEGFAULT
