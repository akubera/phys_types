/**
 * \file quantity.hh
 * \author Andrew Kubera
 * \date Aug 09, 2015
 */

#pragma once

#include <limits>

const float close_to_zero = std::numeric_limits<float>::epsilon();

/**
 * \class Quantity
 * \brief Abstract base class representing basic physical quantities such as mass, length, time.
 */
template <typename T>
class Quantity {
public:
  /**
   * Default Constructor
   * \brief default behavior is to set the enclosed value to 0.0.
   */
  constexpr Quantity();

  /**
   * Constructor
   * \brief Sets the internal value to the provided number.
   */
  constexpr Quantity(T value);

  /**
   * Constructor
   * \brief Sets the internal value to the provided number.
   */
  constexpr Quantity(double value);

protected:
  T _value;
};

template <typename T> constexpr
Quantity<T>::Quantity(): _value(0.0) { /* no-op */ }

template <> constexpr
Quantity<int>::Quantity(): _value(0) { /* no-op */ }

template <typename T> constexpr
Quantity<T>::Quantity(T value): _value(value) { /* no-op */ }

template <typename T> constexpr
Quantity<T>::Quantity(double value): _value(value) { /* no-op */ }

/**
 * \class RatioQuantity
 * \brief Abstract base class representing basic physical quantities such as mass, length, time.
 */
template <class NumeratorType, class DenominatorType>
class RatioQuantity {
public:
  /**
   * Default Constructor
   * \brief default behavior is to set the enclosed value to 0.0.
   */
  constexpr RatioQuantity();

  /**
   * Constructor
   * \brief Sets the internal value to the provided number.
   */
  RatioQuantity(NumeratorType numerator, DenominatorType denominator);

protected:
  NumeratorType _numerator;
  DenominatorType _denominator;
};

template <class NumType, class DenType> constexpr
RatioQuantity<NumType, DenType>::RatioQuantity():
  _numerator(0.0),
  _denominator(close_to_zero)
{ /* no-op */ }


template <class NumType, class DenType>
RatioQuantity<NumType, DenType>::RatioQuantity(NumType num, DenType den):
  _numerator(num),
  _denominator(den)
{

}
