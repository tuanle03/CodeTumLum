
def check(n)
  (2..Math.sqrt(n).round).each do |i|
    return true if n % i == 0
  end
  false
end
 
gets.to_i.times do
	n = gets.to_i
	a = gets.split.map(&:to_i)
	suma = a.sum
	if check(suma)
		pos = ""
		for i in 1..n do
			pos += i.to_s + " "
		end
		puts n
		puts pos
	else
		pos = ""
		for i in 0..n-1 do
			if(check(suma - a[i]))
				puts n-[i+1,1].min
				for j in 1..n do
					if(i + 1 != j)
						pos += j.to_s + " "
					end
				end
				break
			end
		end
		puts pos
	end
end