# Simple pong clone to demonstrate keyboard input and basic collision detection
# Left paddle is controlled with 'a' and 'z', right with ''' and '/'

class Sketch < Processing::App
  def setup
    smooth
    ellipse_mode(CENTER)
    no_fill
    stroke(255)
    frame_rate(60)

    @left_paddle = Paddle.new(200, 200)
    @right_paddle = Paddle.new(600, 200)
    @ball = Ball.new(400, 200)
  end

  def draw
    background(0)

    [@left_paddle, @right_paddle].each { |paddle| paddle.update }

    @ball.collide_with_boundaries
    [@left_paddle, @right_paddle].each { |paddle| @ball.collide_with_paddle(paddle) }
    @ball.move

    [@left_paddle, @right_paddle].each { |paddle| paddle.draw }
    @ball.draw
  end

  def key_pressed
    case key
      when 'a':
        @left_paddle.direction = -1
      when 'z':
        @left_paddle.direction = 1
      when '\'':
        @right_paddle.direction = -1
      when '/':
        @right_paddle.direction = 1
    end
  end

  def key_released
    case key
      when 'a', 'z':
        @left_paddle.direction = 0
      when '\'', '/':
        @right_paddle.direction = 0
    end
  end

  class Paddle
    attr_accessor :position, :radius, :direction

    def initialize(x, y)
      @position = Vector.new(x, y)
      @radius = 20
      @direction = 0
      @speed = 2
    end

    def draw
      stroke_weight(2)
      ellipse(@position.x, @position.y, @radius * 2, @radius * 2)
    end

    def update
      move
      collide_with_boundaries
    end

    def move
      @position.y += @direction * @speed
    end

    def collide_with_boundaries
      @position.y = @position.y < @radius ? @radius : @position.y > 400 - @radius ? 400 - @radius : @position.y
    end
  end

  class Ball
    attr_accessor :position, :velocity, :radius

    def initialize(x, y)
      @position = Vector.new(x, y)
      @velocity = Vector.new(2, 0)
      @radius = 5
    end

    def draw
      stroke_weight(1)
      ellipse(@position.x, @position.y, @radius * 2, @radius * 2)
    end

    def move
      @position += @velocity
    end

    def collide_with_boundaries
      if position.x <= radius || position.x >= 800 - radius
        velocity.x *= -1
      elsif position.y <= radius || position.y >= 400 - radius
        velocity.y *= -1
      end
    end

    def collide_with_paddle(paddle)
      # Check for collision
      distance_vector = position - paddle.position
      return unless distance_vector.squared_length <= (radius + paddle.radius) ** 2

      # Calculate new velocity
      normal = distance_vector.normal.normalized
      @velocity = normal * (velocity * normal) * 2 - velocity

      # Move ball to correct position
      @position = paddle.position + distance_vector.normalized * (2 * (radius + paddle.radius) - distance_vector.length)
    end
  end

  class Vector
    attr_accessor :x, :y

    def initialize(x, y)
      @x, @y = x, y
    end

    def +(other)
      if other.is_a?(Numeric)
        Vector.new(@x + other, @y + other)
      elsif other.is_a?(Vector)
        Vector.new(@x + other.x, @y + other.y)
      else
        self
      end
    end

    def -(other)
      if other.is_a?(Numeric)
        Vector.new(@x - other, @y - other)
      elsif other.is_a?(Vector)
        Vector.new(@x - other.x, @y - other.y)
      else
        self
      end
    end

    def *(other)
      if other.is_a?(Numeric)
        Vector.new(@x * other, @y * other)
      elsif other.is_a?(Vector)
        @x * other.x + @y * other.y
      else
        self
      end
    end

    def length
      Math::sqrt(@x * @x + @y * @y)
    end

    def squared_length
      @x * @x + @y * @y
    end

    def normal
      Vector.new(-@y, @x)
    end

    def normalized
      length = self.length
      Vector.new(@x / length, @y / length)
    end
  end
end

Sketch.new :width => 800, :height => 400
