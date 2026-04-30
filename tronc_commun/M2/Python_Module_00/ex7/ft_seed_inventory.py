def ft_seed_inventory(seed_type: str, quantity: int, unit: str) -> None:
    if (unit == 'packets'):
        print("%s seeds: %d %s available" % (seed_type.capitalize(), quantity, unit))
    if (unit == 'grams'):
        print("%s seeds: %d %s total" % (seed_type.capitalize(), quantity, unit))
    if (unit == 'area'):
        print("%s seeds: covers %d square meters" % (seed_type.capitalize(), quantity))
    else:
        print("Unknown unit type")