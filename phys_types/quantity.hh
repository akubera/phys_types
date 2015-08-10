/**
 * \file quantity.hh
 * \author Andrew Kubera
 * \date Aug 09, 2015
 */

#pragma once

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

protected:
  T _value;
};

template <typename T> constexpr
Quantity<T>::Quantity(): _value(0.0) { /* no-op */ }

template <> constexpr
Quantity<int>::Quantity(): _value(0) { /* no-op */ }

template <typename T> constexpr
Quantity<T>::Quantity(T value): _value(value) { /* no-op */ }
