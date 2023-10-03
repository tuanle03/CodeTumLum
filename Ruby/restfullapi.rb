# frozen_string_literal: true

require 'net/http'
require 'json'

# Kết nối và nhận dữ liệu từ URL
url = URI('https://mocki.io/v1/641d1b89-50ca-401a-9c6c-e149d4a6e562')
response = Net::HTTP.get(url)
data = JSON.parse(response)

# In ra dữ liệu trả về
puts 'Dữ liệu từ URL:'
puts data
puts "\n"

# Đọc và in ra số keyword và danh sách keyword trong thông tin nhóm
team_name = data['team_name']
members = data['members']
keyword_count = 0

members.each do |member|
  keyword_count += member['name'].split.size
  keyword_count += member['student_id'].split.size
end

puts "Số keyword trong thông tin nhóm '#{team_name}': #{keyword_count}"
puts "Danh sách keyword trong thông tin nhóm '#{team_name}':"
members.each do |member|
  puts member['name']
  puts member['student_id']
end
puts "\n"

# Đọc và in ra số thành viên mặc định của nhóm
default_member_count = members.length
puts "Số thành viên mặc định của nhóm '#{team_name}': #{default_member_count}"
puts "\n"

# Điều chỉnh thông tin và in ra màn hình
new_team_info = {
  'team_id' => '1892',
  'team_name' => 'babyboss',
  'members' => [
    {
      'name' => 'Lê Thanh Tuấn',
      'student_id' => '21520518'
    },
    {
      'name' => 'Nguyễn Hoàng Lộc',
      'student_id' => '21522292'
    }
  ],
  'message' => 'Hello class'
}

puts 'Thông tin sau khi điều chỉnh:'
puts new_team_info.to_json
