-- This file defines `ℝ` as the type of equivalence 
-- classes of Cauchy sequences of rational numbers.
import data.real.basic

-----------------------------------------------------
namespace basic_real_analysis

def is_continuous_at (f : ℝ → ℝ) (x₀ : ℝ) := 
  ∀ x, ∀ ε > 0, ∃ η > 0, |x - x₀| < η → |f x - f x₀| < ε

----- euuuuh mauvaise définition ! ?
def is_ucontinuous_at (f : ℝ → ℝ) (x₀ : ℝ) := 
  ∀ ε > 0, ∃ η > 0, ∀ x, |x - x₀| < η → |f x - f x₀| < ε


---------- EXEMPLE
def f₁ (x : ℝ) := x

example : is_continuous_at f₁ 0 :=
begin
  intro h,
  assume ε > 0,
  let η := ε,
  use η,
  use H,
  intro hP,
  apply hP,
end
  
def f₂ (x : ℝ) := 2 * x

example : is_continuous_at f₂ 0 :=
begin 
  intro h,
  assume ε > 0,
  let η := ε / 2,
  use η,
  have ε₂ : ε / 2 > 0 := sorry,
  use ε₂,
  intro hP,
  exact hP,
end

----------
-- prouver que les poly sont continus !
----------

def is_continuous (f : ℝ → ℝ) :=
  ∀ x, is_continuous_at f x

def is_ucontinuous (f : ℝ → ℝ) :=
  ∀ x, is_ucontinuous_at f x

end basic_real_analysis
