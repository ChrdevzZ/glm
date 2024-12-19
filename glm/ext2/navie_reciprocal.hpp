/// @ref ext2_navie_reciprocal
/// @file glm/ext2/navie_reciprocal.hpp
///
/// @defgroup ext2_navie_reciprocal GLM_EXT2_navie_reciprocal
/// @ingroup ext2
///
/// Defines functions for approximate reciprocal (inverse).
///
/// Include <glm/ext2/navie_reciprocal.hpp> to use the features of this extension.
///
/// @see ext_scalar_common
/// @see ext_vector_common

#pragma once


// Dependency:
#include "../detail/setup.hpp"
#include "../common.hpp"


#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_EXT2_navie_reciprocal extension included")
#endif

namespace glm
{
	/// @addtogroup ext2_navie_reciprocal
	/// @{

    /// Reciprocal function that may be faster than the common one
    /// but less accurate.
    /// 
    /// It is almost equivalent to using division directly.
    ///
    template <typename genType>
    GLM_FUNC_DECL genType reciprocal(genType x);

	/// @}
}//namespace glm


#include "navie_reciprocal.inl"
