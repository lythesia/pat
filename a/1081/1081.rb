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

_ = gets
ans = Rational(0)
gets.chomp.split.each { |x| ans += Rational(x) }
puts ans
