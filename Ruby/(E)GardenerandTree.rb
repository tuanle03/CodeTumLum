require 'set'
 
def f(a)
    d = Array.new(a.size)
    q = []
    a.each_with_index do |j, i|
        next if j.size > 1
        q << i
        d[i] = 1
    end
    q.each { |v| a[v].delete(v) }
    while (v = q.shift)
        dv = d[v]
        a[v].each do |u|
            a[u].delete(v)
            next if a[u].size > 1
            next if d[u]
            d[u] = dv + 1
            q << u
        end
    end
    d[0] = 0
    d
end
 
gets.to_i.times do
    gets
    n, k = gets.split.map!(&:to_i)
    a = Array.new(n + 1) { Set.new }
    n.pred.times do
        u, v = gets.split.map!(&:to_i)
        a[u] << v
        a[v] << u
    end 
    d = f(a)
    puts d.count { |di| di > k }
end