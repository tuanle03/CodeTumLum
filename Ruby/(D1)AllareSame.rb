gets.to_i.times do
	n = gets.to_i
	a = gets.split.map(&:to_i)
	a = a.sort
	res = 0; tmp = a[0] 
	a.map! {|ai| ai - tmp}
	a.map! {|x| res = res.gcd(x)}
	puts res != 0? res:-1
end