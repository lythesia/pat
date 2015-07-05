#!/usr/bin/env ruby

class Acc
  attr_accessor :name, :pass, :mod
  def initialize(s)
    @name, @pass = s.split
    @mod = false
  end
  def valid?
    pw = @pass.gsub('1', '@').gsub('0', '%').gsub('l', 'L').gsub('O', 'o')
    if pw != @pass
      @pass = pw
      return false
    else
      return true
    end
  end
  def to_s
    "#{@name} #{@pass}"
  end
end
ans = []
n = gets.chomp.to_i
n.times do
  acc = Acc.new gets.chomp
  ans << acc unless acc.valid?
end

if ans.empty?
  if n == 1
    puts "There is 1 account and no account is modified"
  else
    puts "There are #{n} accounts and no account is modified"
  end
else
  puts ans.length
  ans.each { |x| puts x }
end
