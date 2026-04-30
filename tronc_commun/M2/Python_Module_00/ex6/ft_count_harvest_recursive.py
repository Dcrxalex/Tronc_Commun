def ft_count_harvest_recursive(n):
    n = 1
    print('Days until harvest: ')
    lim = input()
    if (int(n) < int(lim)):
        print('Day :', n)
    if (int(n) == int(lim)):
        print('Day :')
        return (n)
    return ft_count_harvest_recursive(n + 1)