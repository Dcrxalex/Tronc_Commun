def ft_plant_age():
    print('Enter plant age in days: ')
    age = input()
    if (int(age) > 60):
        print('Plant is ready to harvest!')
    else:
        print('Plant needs more time to grow.')