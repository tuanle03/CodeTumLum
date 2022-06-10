gets.to_i.times do
	n, m = gets.split.map(&:to_i)
	vec = Array.new(n+1) { 0 }
	for i in 0..m-1 do
		x, y, z = gets.split.map(&:to_i)
		vec[y] = 1
	end
	pos = 0
	for i in 1..n do
		if vec[i] == 0
			pos = i
			break
		end
	end
	for i in 1..n do
		if pos == i
			next
		end
		puts "#{pos} #{i}"
	end
end
