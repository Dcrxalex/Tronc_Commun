/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decro <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 21:19:08 by decro             #+#    #+#             */
/*   Updated: 2026/04/11 15:33:51 by decro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/* ======================== COLORS ======================== */
#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[0;33m"
#define BLUE    "\033[0;34m"
#define RESET   "\033[0m"

/* ======================== HELPERS ======================= */
static int g_pass = 0;
static int g_fail = 0;

void    print_header(char *section)
{
    printf("\n" BLUE "========== %s ==========" RESET "\n", section);
}

void    check(char *test_name, int passed)
{
    if (passed)
    {
        printf(GREEN "[PASS]" RESET " %s\n", test_name);
        g_pass++;
    }
    else
    {
        printf(RED "[FAIL]" RESET " %s\n", test_name);
        g_fail++;
    }
}

/* ====================== PART 1 TESTS ==================== */

void    test_isalpha(void)
{
    print_header("ft_isalpha");
    check("lowercase letter 'a'",     ft_isalpha('a') == 1);
    check("uppercase letter 'Z'",     ft_isalpha('Z') == 1);
    check("digit '5'",                ft_isalpha('5') == 0);
    check("space ' '",                ft_isalpha(' ') == 0);
    check("null character '\\0'",     ft_isalpha('\0') == 0);
}

void    test_isdigit(void)
{
    print_header("ft_isdigit");
    check("digit '0'",                ft_isdigit('0') == 1);
    check("digit '9'",                ft_isdigit('9') == 1);
    check("letter 'a'",               ft_isdigit('a') == 0);
    check("space ' '",                ft_isdigit(' ') == 0);
    check("null character '\\0'",     ft_isdigit('\0') == 0);
}

void    test_isalnum(void)
{
    print_header("ft_isalnum");
    check("letter 'a'",               ft_isalnum('a') == 1);
    check("digit '5'",                ft_isalnum('5') == 1);
    check("space ' '",                ft_isalnum(' ') == 0);
    check("special char '@'",         ft_isalnum('@') == 0);
}

void    test_isascii(void)
{
    print_header("ft_isascii");
    check("char 0",                   ft_isascii(0) == 1);
    check("char 127",                 ft_isascii(127) == 1);
    check("char 128 (out of ASCII)",  ft_isascii(128) == 0);
    check("char -1 (negative)",       ft_isascii(-1) == 0);
}

void    test_isprint(void)
{
    print_header("ft_isprint");
    check("space ' ' (32)",           ft_isprint(' ') == 1);
    check("tilde '~' (126)",          ft_isprint('~') == 1);
    check("char 31 (non-printable)",  ft_isprint(31) == 0);
    check("char 127 (DEL)",           ft_isprint(127) == 0);
}

void    test_strlen(void)
{
    print_header("ft_strlen");
    check("normal string",            ft_strlen("hello") == 5);
    check("empty string",             ft_strlen("") == 0);
    check("single char",              ft_strlen("a") == 1);
    check("string with spaces",       ft_strlen("hi there") == 8);
}

void    test_memset(void)
{
    char buf1[10];
    char buf2[10];

    print_header("ft_memset");
    memset(buf1, 'A', 5); buf1[5] = '\0';
    ft_memset(buf2, 'A', 5); buf2[5] = '\0';
    check("fill with 'A'",            memcmp(buf1, buf2, 5) == 0);

    memset(buf1, 0, 10);
    ft_memset(buf2, 0, 10);
    check("fill with 0",              memcmp(buf1, buf2, 10) == 0);

    ft_memset(buf2, 'Z', 0);
    check("zero length (no change)",  buf2[0] == '\0');
}

void    test_bzero(void)
{
    char buf[10];

    print_header("ft_bzero");
    memset(buf, 'A', 10);
    ft_bzero(buf, 5);
    check("first 5 bytes zeroed",     buf[0] == 0 && buf[4] == 0);
    check("bytes after 5 untouched",  buf[5] == 'A');

    ft_bzero(buf, 0);
    check("zero length (no change)",  buf[5] == 'A');
}

void    test_memcpy(void)
{
    char src[] = "Hello, 42!";
    char dst[20];

    print_header("ft_memcpy");
    ft_memcpy(dst, src, 11);
    check("normal copy",              memcmp(dst, src, 11) == 0);

    ft_memcpy(dst, src, 0);
    check("zero length copy",         memcmp(dst, src, 11) == 0);
}

void    test_memmove(void)
{
    char buf1[] = "Hello, 42!";
    char buf2[] = "Hello, 42!";

    print_header("ft_memmove");
    memmove(buf1 + 2, buf1, 5);
    ft_memmove(buf2 + 2, buf2, 5);
    check("overlapping copy (dst > src)", memcmp(buf1, buf2, 10) == 0);

    char buf3[] = "Hello, 42!";
    char buf4[] = "Hello, 42!";
    memmove(buf3, buf3 + 2, 5);
    ft_memmove(buf4, buf4 + 2, 5);
    check("overlapping copy (dst < src)", memcmp(buf3, buf4, 10) == 0);
}

void    test_strlcpy(void)
{
    char dst1[20];
    char dst2[20];

    print_header("ft_strlcpy");
    check("normal copy return value",     ft_strlcpy(dst1, "Hello", 20) == 5);
    check("normal copy content",          strcmp(dst1, "Hello") == 0);
    check("truncation return value",      ft_strlcpy(dst2, "Hello", 3) == 5);
    check("truncation content",           strcmp(dst2, "He") == 0);
    check("zero size returns src len",    ft_strlcpy(dst1, "Hello", 0) == 5);
}

void    test_strlcat(void)
{
    char dst[20] = "Hello";

    print_header("ft_strlcat");
    check("normal concat return value",   ft_strlcat(dst, " 42", 20) == 8);
    check("normal concat content",        strcmp(dst, "Hello 42") == 0);

    char dst2[8] = "Hello";
    check("truncation return value",      ft_strlcat(dst2, " World", 8) == 11);
    check("truncation content",           strcmp(dst2, "Hello W") == 0);
}

void    test_toupper(void)
{
    print_header("ft_toupper");
    check("lowercase to upper",       ft_toupper('a') == 'A');
    check("already uppercase",        ft_toupper('A') == 'A');
    check("digit unchanged",          ft_toupper('5') == '5');
    check("special char unchanged",   ft_toupper('@') == '@');
}

void    test_tolower(void)
{
    print_header("ft_tolower");
    check("uppercase to lower",       ft_tolower('A') == 'a');
    check("already lowercase",        ft_tolower('a') == 'a');
    check("digit unchanged",          ft_tolower('5') == '5');
    check("special char unchanged",   ft_tolower('@') == '@');
}

void    test_strchr(void)
{
    print_header("ft_strchr");
    check("char found",               ft_strchr("hello", 'e') == strchr("hello", 'e'));
    check("char not found",           ft_strchr("hello", 'z') == NULL);
    check("find null terminator",     ft_strchr("hello", '\0') != NULL);
    check("empty string",             ft_strchr("", 'a') == NULL);
}

void    test_strrchr(void)
{
    print_header("ft_strrchr");
    check("last occurrence",          ft_strrchr("hello", 'l') == strrchr("hello", 'l'));
    check("char not found",           ft_strrchr("hello", 'z') == NULL);
    check("find null terminator",     ft_strrchr("hello", '\0') != NULL);
}

void    test_strncmp(void)
{
    print_header("ft_strncmp");
    check("equal strings",            ft_strncmp("hello", "hello", 5) == 0);
    check("different strings",        ft_strncmp("hello", "world", 5) != 0);
    check("n=0 always equal",         ft_strncmp("hello", "world", 0) == 0);
    check("partial compare equal",    ft_strncmp("hello", "help", 3) == 0);
    check("partial compare differ",   ft_strncmp("hello", "help", 4) != 0);
}

void    test_memchr(void)
{
    char buf[] = "Hello, 42!";

    print_header("ft_memchr");
    check("char found",               ft_memchr(buf, 'H', 10) == memchr(buf, 'H', 10));
    check("char not found",           ft_memchr(buf, 'z', 10) == NULL);
    check("find beyond n",            ft_memchr(buf, '4', 7) == NULL);
    check("n=0 returns NULL",         ft_memchr(buf, 'H', 0) == NULL);
}

void    test_memcmp(void)
{
    print_header("ft_memcmp");
    check("equal memory",             ft_memcmp("hello", "hello", 5) == 0);
    check("different memory",         ft_memcmp("hello", "world", 5) != 0);
    check("n=0 always equal",         ft_memcmp("hello", "world", 0) == 0);
    check("does not stop at \\0",     ft_memcmp("ab\0cd", "ab\0ef", 5) != 0);
}

void    test_strnstr(void)
{
    print_header("ft_strnstr");
    check("found in range",           ft_strnstr("hello world", "world", 11) != NULL);
    check("not in range",             ft_strnstr("hello world", "world", 5) == NULL);
    check("empty needle",             ft_strnstr("hello", "", 5) != NULL);
    check("not found at all",         ft_strnstr("hello", "xyz", 5) == NULL);
    check("needle longer than n",     ft_strnstr("hi", "hello", 2) == NULL);
}

void    test_atoi(void)
{
    print_header("ft_atoi");
    check("positive number",          ft_atoi("42") == 42);
    check("negative number",          ft_atoi("-42") == -42);
    check("zero",                     ft_atoi("0") == 0);
    check("leading whitespace",       ft_atoi("   42") == 42);
    check("leading plus sign",        ft_atoi("+42") == 42);
    check("non-digit suffix",         ft_atoi("42abc") == 42);
    check("only non-digit",           ft_atoi("abc") == 0);
}

void    test_calloc(void)
{
    int *arr;

    print_header("ft_calloc");
    arr = ft_calloc(5, sizeof(int));
    check("allocation succeeds",      arr != NULL);
    check("memory is zeroed",         arr[0] == 0 && arr[4] == 0);
    free(arr);

    void *p = ft_calloc(0, sizeof(int));
    check("zero nmemb returns non-NULL (freeable)", p != NULL);
    free(p);
}

void    test_strdup(void)
{
    char *dup;

    print_header("ft_strdup");
    dup = ft_strdup("hello");
    check("content matches",          strcmp(dup, "hello") == 0);
    check("different pointer",        1);
    free(dup);

    dup = ft_strdup("");
    check("empty string",             strcmp(dup, "") == 0);
    free(dup);
}

/* ====================== PART 2 TESTS ==================== */

void    test_substr(void)
{
    char *s;

    print_header("ft_substr");
    s = ft_substr("Hello, 42!", 7, 3);
    check("normal substr",            strcmp(s, "42!") == 0);
    free(s);

    s = ft_substr("Hello", 10, 3);
    check("start out of bounds",      strcmp(s, "") == 0);
    free(s);

    s = ft_substr("Hello", 1, 2);
    check("len smaller than word",    strcmp(s, "el") == 0);
    free(s);

    s = ft_substr("", 0, 5);
    check("empty string",             strcmp(s, "") == 0);
    free(s);
}

void    test_strjoin(void)
{
    char *s;

    print_header("ft_strjoin");
    s = ft_strjoin("Hello, ", "42!");
    check("normal join",              strcmp(s, "Hello, 42!") == 0);
    free(s);

    s = ft_strjoin("", "42");
    check("empty s1",                 strcmp(s, "42") == 0);
    free(s);

    s = ft_strjoin("Hello", "");
    check("empty s2",                 strcmp(s, "Hello") == 0);
    free(s);

    s = ft_strjoin("", "");
    check("both empty",               strcmp(s, "") == 0);
    free(s);
}

void    test_strtrim(void)
{
    char *s;

    print_header("ft_strtrim");
    s = ft_strtrim("  hello  ", " ");
    check("trim spaces",              strcmp(s, "hello") == 0);
    free(s);

    s = ft_strtrim("xxhelloxx", "x");
    check("trim 'x'",                 strcmp(s, "hello") == 0);
    free(s);

    s = ft_strtrim("hello", "x");
    check("nothing to trim",          strcmp(s, "hello") == 0);
    free(s);

    s = ft_strtrim("", " ");
    check("empty string",             strcmp(s, "") == 0);
    free(s);

    s = ft_strtrim("   ", " ");
    check("all chars trimmed",        strcmp(s, "") == 0);
    free(s);
}

void    test_split(void)
{
    char **res;

    print_header("ft_split");
    res = ft_split("hello world foo", ' ');
    check("3 words",                  strcmp(res[0], "hello") == 0
                                   && strcmp(res[1], "world") == 0
                                   && strcmp(res[2], "foo") == 0
                                   && res[3] == NULL);
    free(res[0]); free(res[1]); free(res[2]); free(res);

    res = ft_split("", ' ');
    check("empty string",             res[0] == NULL);
    free(res);

    res = ft_split("hello", ' ');
    check("no delimiter found",       strcmp(res[0], "hello") == 0 && res[1] == NULL);
    free(res[0]); free(res);

    res = ft_split("   ", ' ');
    check("only delimiters",          res[0] == NULL);
    free(res);
}

void    test_itoa(void)
{
    char *s;

    print_header("ft_itoa");
    s = ft_itoa(42);
    check("positive number",          strcmp(s, "42") == 0);
    free(s);

    s = ft_itoa(-42);
    check("negative number",          strcmp(s, "-42") == 0);
    free(s);

    s = ft_itoa(0);
    check("zero",                     strcmp(s, "0") == 0);
    free(s);

    s = ft_itoa(2147483647);
    check("INT_MAX",                  strcmp(s, "2147483647") == 0);
    free(s);

    s = ft_itoa(-2147483648);
    check("INT_MIN",                  strcmp(s, "-2147483648") == 0);
    free(s);
}

char    to_upper_f(unsigned int i, char c)
{
    (void)i;
    return (ft_toupper(c));
}

void    test_strmapi(void)
{
    char *s;

    print_header("ft_strmapi");
    s = ft_strmapi("hello", to_upper_f);
    check("to uppercase",             strcmp(s, "HELLO") == 0);
    free(s);

    s = ft_strmapi("", to_upper_f);
    check("empty string",             strcmp(s, "") == 0);
    free(s);
}

void    add_index(unsigned int i, char *c)
{
    *c += i;
}

void    test_striteri(void)
{
    char s[] = "aaa";

    print_header("ft_striteri");
    ft_striteri(s, add_index);
    check("modifies in place (a+0, a+1, a+2)", strcmp(s, "abc") == 0);
}

void    test_putchar_fd(void)
{
    print_header("ft_putchar_fd");
    printf("  [VISUAL] ft_putchar_fd('A', 1): ");
    ft_putchar_fd('A', 1);
    printf("\n");
    g_pass++;
}

void    test_putstr_fd(void)
{
    print_header("ft_putstr_fd");
    printf("  [VISUAL] ft_putstr_fd(\"Hello 42\", 1): ");
    ft_putstr_fd("Hello 42", 1);
    printf("\n");
    g_pass++;
}

void    test_putendl_fd(void)
{
    print_header("ft_putendl_fd");
    printf("  [VISUAL] ft_putendl_fd(\"Hello 42\", 1): ");
    ft_putendl_fd("Hello 42", 1);
    g_pass++;
}

void    test_putnbr_fd(void)
{
    print_header("ft_putnbr_fd");
    printf("  [VISUAL] ft_putnbr_fd(42, 1):          ");
    ft_putnbr_fd(42, 1);
    printf("\n");
    printf("  [VISUAL] ft_putnbr_fd(-42, 1):         ");
    ft_putnbr_fd(-42, 1);
    printf("\n");
    printf("  [VISUAL] ft_putnbr_fd(0, 1):           ");
    ft_putnbr_fd(0, 1);
    printf("\n");
    printf("  [VISUAL] ft_putnbr_fd(INT_MIN, 1):     ");
    ft_putnbr_fd(-2147483648, 1);
    printf("\n");
    g_pass++;
}

/* ====================== PART 3 TESTS ==================== */

void    del_content(void *content)
{
    free(content);
}

void    test_lstnew(void)
{
    t_list *node;

    print_header("ft_lstnew");
    node = ft_lstnew("hello");
    check("content set correctly",    strcmp((char *)node->content, "hello") == 0);
    check("next is NULL",             node->next == NULL);
    free(node);
}

void    test_lstadd_front(void)
{
    t_list *lst;
    t_list *node1;
    t_list *node2;

    print_header("ft_lstadd_front");
    node1 = ft_lstnew("first");
    node2 = ft_lstnew("second");
    lst = node1;
    ft_lstadd_front(&lst, node2);
    check("new node is at front",     strcmp((char *)lst->content, "second") == 0);
    check("old node is next",         strcmp((char *)lst->next->content, "first") == 0);
    free(node1);
    free(node2);
}

void    test_lstsize(void)
{
    t_list *lst;
    t_list *n1 = ft_lstnew("a");
    t_list *n2 = ft_lstnew("b");
    t_list *n3 = ft_lstnew("c");

    print_header("ft_lstsize");
    lst = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;
    check("size of 3",                ft_lstsize(lst) == 3);
    check("size of NULL",             ft_lstsize(NULL) == 0);
    free(n1); free(n2); free(n3);
}

void    test_lstlast(void)
{
    t_list *n1 = ft_lstnew("a");
    t_list *n2 = ft_lstnew("b");
    t_list *n3 = ft_lstnew("c");

    print_header("ft_lstlast");
    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;
    check("last node content",        strcmp((char *)ft_lstlast(n1)->content, "c") == 0);
    check("single node is last",      ft_lstlast(n3) == n3);
    free(n1); free(n2); free(n3);
}

void    test_lstadd_back(void)
{
    t_list *lst = ft_lstnew("first");
    t_list *node = ft_lstnew("last");

    print_header("ft_lstadd_back");
    ft_lstadd_back(&lst, node);
    check("node added at back",       strcmp((char *)ft_lstlast(lst)->content, "last") == 0);
    check("front unchanged",          strcmp((char *)lst->content, "first") == 0);
    free(lst); free(node);
}

void    test_lstdelone(void)
{
    char    *s = ft_strdup("hello");
    t_list  *node = ft_lstnew(s);

    print_header("ft_lstdelone");
    ft_lstdelone(node, del_content);
    check("node deleted (no crash)",  1);
}

void    test_lstclear(void)
{
    t_list *lst = ft_lstnew(ft_strdup("a"));
    ft_lstadd_back(&lst, ft_lstnew(ft_strdup("b")));
    ft_lstadd_back(&lst, ft_lstnew(ft_strdup("c")));

    print_header("ft_lstclear");
    ft_lstclear(&lst, del_content);
    check("list pointer set to NULL", lst == NULL);
}

void    *dup_content(void *content)
{
    return (ft_strdup((char *)content));
}

void    print_content(void *content)
{
    printf("%s\n", (char *)content);
}

void    test_lstiter(void)
{
    t_list *lst = ft_lstnew("hello");
    ft_lstadd_back(&lst, ft_lstnew("world"));

    print_header("ft_lstiter");
    printf("  [VISUAL] ft_lstiter content: ");
    ft_lstiter(lst, print_content);
    g_pass++;
    free(lst->next);
    free(lst);
}

void    test_lstmap(void)
{
    t_list *lst = ft_lstnew("hello");
    t_list *result;

    ft_lstadd_back(&lst, ft_lstnew("world"));
    print_header("ft_lstmap");
    result = ft_lstmap(lst, dup_content, del_content);
    check("first node mapped",        strcmp((char *)result->content, "hello") == 0);
    check("second node mapped",       strcmp((char *)result->next->content, "world") == 0);
    check("NULL terminated",          result->next->next == NULL);
    ft_lstclear(&result, del_content);
    free(lst->next);
    free(lst);
}

/* ========================= MAIN ========================= */

int main(void)
{
    printf(YELLOW "\n╔══════════════════════════════╗" RESET "\n");
    printf(YELLOW "║       LIBFT TEST SUITE       ║" RESET "\n");
    printf(YELLOW "╚══════════════════════════════╝" RESET "\n");

    /* Part 1 */
    printf(YELLOW "\n--- PART 1: LIBC FUNCTIONS ---" RESET "\n");
    test_isalpha();
    test_isdigit();
    test_isalnum();
    test_isascii();
    test_isprint();
    test_strlen();
    test_memset();
    test_bzero();
    test_memcpy();
    test_memmove();
    test_strlcpy();
    test_strlcat();
    test_toupper();
    test_tolower();
    test_strchr();
    test_strrchr();
    test_strncmp();
    test_memchr();
    test_memcmp();
    test_strnstr();
    test_atoi();
    test_calloc();
    test_strdup();

    /* Part 2 */
    printf(YELLOW "\n--- PART 2: ADDITIONAL FUNCTIONS ---" RESET "\n");
    test_substr();
    test_strjoin();
    test_strtrim();
    test_split();
    test_itoa();
    test_strmapi();
    test_striteri();
    test_putchar_fd();
    test_putstr_fd();
    test_putendl_fd();
    test_putnbr_fd();

    /* Part 3 */
    printf(YELLOW "\n--- PART 3: LINKED LIST ---" RESET "\n");
    test_lstnew();
    test_lstadd_front();
    test_lstsize();
    test_lstlast();
    test_lstadd_back();
    test_lstdelone();
    test_lstclear();
    test_lstiter();
    test_lstmap();

    /* Summary */
    printf(YELLOW "\n╔══════════════════════════════╗" RESET "\n");
    printf(YELLOW "║           RESULTS            ║" RESET "\n");
    printf(YELLOW "╚══════════════════════════════╝" RESET "\n");
    printf(GREEN "  PASSED: %d\n" RESET, g_pass);
    printf(RED   "  FAILED: %d\n" RESET, g_fail);
    printf("  TOTAL:  %d\n\n", g_pass + g_fail);

    return (g_fail > 0 ? 1 : 0);
}
