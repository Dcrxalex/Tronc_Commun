def ft_count_harvest_recursive():
	days = int(input("Days until harvest: "))
	def count(current):
		if current > days:
			print ("Harvest time!")
			return
		print(f"Day {current}")
		count(current + 1)
	count(1)
