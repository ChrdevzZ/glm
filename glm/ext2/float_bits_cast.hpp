/// @ref ext2_float_bits_cast
/// @file glm/ext2/float_bits_cast.hpp
///
/// @defgroup ext2_float_bits_cast GLM_EXT2_float_bits_cast
/// @ingroup ext2
///
/// Defines functions for float-bits casting.
///
/// Include <glm/ext2/float_bits_cast.hpp> to use the features of this extension.
///
/// @see ext_scalar_common
/// @see ext_vector_common

#pragma once


// Dependency:
#include "../detail/setup.hpp"
#include "../fwd.hpp"
#include "../common.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_EXT2_float_bits_cast extension included")
#endif

namespace glm
{
	/// @addtogroup ext2_float_bits_cast
	/// @{


    /// Returns a unsigned integer value representing
    /// the encoding of a floating-point value. The floatingpoint
    /// value's bit-level representation is preserved. (32-bit)
    GLM_FUNC_DECL uint float_as_bits(float v);
    
    /// Returns a unsigned integer value representing
    /// the encoding of a floating-point value. The floatingpoint
    /// value's bit-level representation is preserved. (64-bit)
    GLM_FUNC_DECL uint64 float_as_bits(double v);
    
    /// Returns a unsigned integer value representing
    /// the encoding of a floating-point value. The floatingpoint
    /// value's bit-level representation is preserved. (32-bit)
    ///
    /// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
    /// @tparam Q Value from qualifier enum
    template<length_t L, qualifier Q>
    GLM_FUNC_DECL vec<L, uint, Q> float_as_bits(vec<L, float, Q> const& v);
    
    /// Returns a unsigned integer value representing
    /// the encoding of a floating-point value. The floatingpoint
    /// value's bit-level representation is preserved. (64-bit)
    ///
    /// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
    /// @tparam Q Value from qualifier enum
    template<length_t L, qualifier Q>
    GLM_FUNC_DECL vec<L, uint64, Q> float_as_bits(vec<L, double, Q> const& v);
    
    /// Returns a floating-point value corresponding to a
    /// unsigned integer encoding of a floating-point value.
    /// If an inf or NaN is passed in, it will not signal, and the
    /// resulting floating point value is unspecified. Otherwise,
    /// the bit-level representation is preserved. (32-bit)
    GLM_FUNC_DECL float bits_as_float(uint v);
    
    /// Returns a floating-point value corresponding to a
    /// unsigned integer encoding of a floating-point value.
    /// If an inf or NaN is passed in, it will not signal, and the
    /// resulting floating point value is unspecified. Otherwise,
    /// the bit-level representation is preserved. (64-bit)
    GLM_FUNC_DECL double bits_as_float(uint64 v);
    
    /// Returns a floating-point value corresponding to a
    /// unsigned integer encoding of a floating-point value.
    /// If an inf or NaN is passed in, it will not signal, and the
    /// resulting floating point value is unspecified. Otherwise,
    /// the bit-level representation is preserved. (32-bit)
    ///
    /// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
    /// @tparam Q Value from qualifier enum
    template<length_t L, qualifier Q>
    GLM_FUNC_DECL vec<L, float, Q> bits_as_float(vec<L, uint, Q> const& v);
    
    /// Returns a floating-point value corresponding to a
    /// unsigned integer encoding of a floating-point value.
    /// If an inf or NaN is passed in, it will not signal, and the
    /// resulting floating point value is unspecified. Otherwise,
    /// the bit-level representation is preserved. (64-bit)
    ///
    /// @tparam L Integer between 1 and 4 included that qualify the dimension of the vector
    /// @tparam Q Value from qualifier enum
    template<length_t L, qualifier Q>
    GLM_FUNC_DECL vec<L, double, Q> bits_as_float(vec<L, uint64, Q> const& v);


	/// @}
}//namespace glm


#include "float_bits_cast.inl"
