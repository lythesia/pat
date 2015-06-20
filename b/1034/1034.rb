#!/usr/bin/env ruby

class Rational
  def to_s
    f = self
    f = -f if f < 0
    if self < 0
      "(-#{f})"
    elsif f.truncate == 0
      f == 0 ? "0" : "#{f.numerator}/#{denominator}"
    else
      f -= f.truncate
      f == 0 ? "#{self.truncate}" : "#{self.truncate} #{f.numerator}/#{f.denominator}"
    end
  end
end
a, b = gets.split.map { |x| Rational(x) }
puts "#{a} + #{b} = #{a + b}"
puts "#{a} - #{b} = #{a - b}"
puts "#{a} * #{b} = #{a * b}"
print "#{a} / #{b} = "
begin
  puts a / b
rescue ZeroDivisionError
  puts "Inf"
end
