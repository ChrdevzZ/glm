/// @ref ext2_minmax
/// @file glm/ext2/minmax.hpp
///
/// @see core (dependence)
///
/// @defgroup ext2_minmax GLM_EXT2_minmax
/// @ingroup ext2
///
/// Defines functions for approximate reciprocal (inverse).
///
/// Include <glm/ext2/minmax.hpp> to use the features of this extension.
///
/// @brief Returns the lowest (min) and the greatest (max) of the given values.
///
/// @see ext_scalar_common
/// @see ext_vector_common
/// @see gtx_extended_min_max
/// @see gtx_associated_min_max

#pragma once


// Dependency:
#include "../detail/setup.hpp"
#include "../fwd.hpp"
#include "../common.hpp"
#include "../ext/scalar_common.hpp"
#include "../ext/vector_common.hpp"

#include <tuple> // For std::pair

#ifndef GLM_ENABLE_ADDITIONAL_EXTENSIONS
#	error "GLM: GLM_EXT2_minmax is an additional extension and may change in the future. Use #define GLM_ENABLE_ADDITIONAL_EXTENSIONS before including it, if you really want to use it."
#elif GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_EXT2_minmax extension included")
#endif

namespace glm
{
    /// @addtogroup ext2_minmax
    /// @{

    
	/// Returns (y, x) pair if y < x; otherwise, it returns (x, y).
	///
	/// @tparam genType Floating-point or integer; scalar or vector types.
	template<typename genType>
	GLM_FUNC_DECL GLM_CONSTEXPR std::pair<genType, genType> minmax(genType x, genType y);

	/// Returns (y, x) pair if y < x; otherwise, it returns (x, y).
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point or integer scalar types
	/// @tparam Q Value from qualifier enum
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR std::pair<vec<L, T, Q>, vec<L, T, Q>> minmax(vec<L, T, Q> const& x, T y);

	/// Returns (y, x) pair if y < x; otherwise, it returns (x, y).
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point or integer scalar types
	/// @tparam Q Value from qualifier enum
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR std::pair<vec<L, T, Q>, vec<L, T, Q>> minmax(T x, vec<L, T, Q> const& y);

	/// Returns (y, x) pair if y < x; otherwise, it returns (x, y).
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point or integer scalar types
	/// @tparam Q Value from qualifier enum
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR std::pair<vec<L, T, Q>, vec<L, T, Q>> minmax(vec<L, T, Q> const& x, vec<L, T, Q> const& y);

	/// Returns the minimum and maximum component-wise values pair of 3 inputs
	///
	/// @tparam genType A floating-point scalar type.
	template<typename genType>
	GLM_FUNC_DECL GLM_CONSTEXPR std::pair<genType, genType> minmax(genType a, genType b, genType c);

	/// Returns the minimum and maximum component-wise values pair of 4 inputs
	///
	/// @tparam genType A floating-point scalar type.
	template<typename genType>
	GLM_FUNC_DECL GLM_CONSTEXPR std::pair<genType, genType> minmax(genType a, genType b, genType c, genType d);

	/// Return the minimum and maximum component-wise values pair of 3 inputs
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point or integer scalar types
	/// @tparam Q Value from qualifier enum
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR std::pair<vec<L, T, Q>, vec<L, T, Q>> minmax(vec<L, T, Q> const& a, vec<L, T, Q> const& b, vec<L, T, Q> const& c);

	/// Return the minimum and maximum component-wise values pair of 4 inputs
	///
	/// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
	/// @tparam T Floating-point or integer scalar types
	/// @tparam Q Value from qualifier enum
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR std::pair<vec<L, T, Q>, vec<L, T, Q>> minmax(vec<L, T, Q> const& a, vec<L, T, Q> const& b, vec<L, T, Q> const& c, vec<L, T, Q> const& d);


    /// @}
}//namespace glm


#include "minmax.inl"
