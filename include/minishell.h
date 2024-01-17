/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 08:31:10 by blax              #+#    #+#             */
/*   Updated: 2024/01/17 21:19:04 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "enum.h"
# include "structures.h"
# include "libft.h"

# define _POSIX_C_SOURCE 200809L
# include <signal.h>
# include <unistd.h> // access
# include <stdlib.h> // malloc
# include <readline/readline.h> // readline
# include <readline/history.h> // addhistory
#include <sys/wait.h> //wait
# include <stdio.h>
# include <stdbool.h>
# include <errno.h>
// # include <bsd/string.h>
// # include <stddef.h> //ft_strcmp

extern int g_info;

//builtins.c
void	ft_echo(char **argv);
void	ft_env(char **envp);
void	ft_pwd(void);
int		is_valid_env_name(char *name);
void	ft_unset(char **args, t_list **env);
void	ft_exit(char **args);
void	ft_export(char **args, t_list **env);

// syntax_utils.c
bool is_quote(char c);
bool is_space(char c);
bool is_syntax_char(char c);
bool is_syntax(char c);
bool is_double_symbol(t_data *data, int i, char c);

// syntax.c
bool check_before(t_data *data, int i);
bool check_after(t_data *data, int i);
void update_is_quote(t_data *data, char letter);
void verif_syntax(t_data *data);

// parser.c
void delimit_node(t_data *data, int *i);
bool skip_spaces(t_data *data, int *i);
void parser(t_data *data);

// trim.c
int nb_trim_left(char *str);
int nb_trim_right(char *str);
char *trim_str(char *str);
// ----------------------------------------------------------------------

// free.c
// void free_tab_exec(t_node *node);
void free_nodes(t_node *node);
void free_data(t_data *data);

// error.c
bool ft_error(char *str);
bool ft_error_2(char *str);

// ------------------ Lexer --------------------
// lexer.c
void ft_lexer(t_data *data);
bool process_string(t_data *data, int *i);
bool process_quote(t_data *data, int *i);
bool process_syntax(t_data *data, int *i);
bool is_empty_quotes(t_data *data, int *i);

// lexer_token.c
t_token *create_token(t_data *data, int end);
void add_token(t_data *data, int end);

void process_for_token(t_data *data, int *i);
// void lexer_node(t_data *data, t_node *node);

// lexer_utils_1.c
char *transform_enum_type_token(t_state num_c);
char *transform_enum_quote(t_stick_token num_c);
void print_tokens(t_token *tokens);

// lexer_utils_2.c
t_stick_token	ft_type_char(char c);
void	init_data(t_data *data, char *str);

// ------------------ Parser --------------------

// parser.c
void	parse_input(t_data *data);
// bool is_empty_token(t_token *token);

// parser_utils_1.c
bool	is_command(t_token *token);
bool	is_pipe(const char *str);
bool	is_option(const char *str);
bool	is_redirection(const char *str);
t_state	what_redirection(char *str);

// parser_quote.c
void parse_quote_tokens(t_data *data);
void remove_quotes(char *input, char type_quote);

// parser_type_token.c
void	update_token_type(t_token *token, t_state *current_state);
void	update_token_type_suite(t_token *token, t_state *current_state);
void	determine_token_types(t_data *data);

// ------------------ Expander --------------------

// expander.c
void expand_tokens(t_data *data);
// void replace_token_str(t_token *token, char *new_value);
// void print_expanded_tokens(t_token *tokens);

// expander_utils_1.c
char* expand_variables(const char *input);
char* process_dollar_sign(const char **ptr, char *result);
char* process_text_until_next_dollar(const char **ptr, char *result);

// expander_utils_2.c
char* append_variable_value(char *result, const char *varName);
char* extract_var_name(const char **ptr);
char* copy_until_char(char *dest, const char *src, char delimiter);

// // file_redirect.c

// int apply_redir_in(t_tree *tree, t_ast_node *node);
// int apply_redir_append(t_tree *tree, t_ast_node *node);
// int apply_redir_heredoc(t_tree *tree, t_ast_node *node);
// int apply_redir_out(t_tree *tree, t_ast_node *node);
// void restore_std(t_tree *tree, int save_fd[2]);

// // exec.c

// void execute_ast(t_tree *tree, t_ast_node *ast);
// int execute_pipe_node(t_tree *tree, t_ast_node *node);
// int	execute_redir_node(t_tree *tree, t_ast_node *node);
// void execute_command_node(t_ast_node *node);

#endif
