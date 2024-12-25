/// @ref ext2_navie_reciprocal

namespace glm{
namespace detail
{
    template<length_t L, typename T, qualifier Q, bool Aligned>
    struct compute_reciprocal
    {
        GLM_FUNC_QUALIFIER static vec<L, T, Q> call(vec<L, T, Q> const& x)
        {
            return static_cast<T>(1) / x;
        }
    };
}//namespace detail

    // reciprocal
    template<typename genType>
    GLM_FUNC_QUALIFIER genType reciprocal(genType x)
    {
        GLM_STATIC_ASSERT( std::numeric_limits<genType>::is_iec559 || GLM_CONFIG_UNRESTRICTED_FLOAT, 
                           "'reciprocal' only accept floating-point input" );
    
        return genType(1) / x;
    }

    template<length_t L, typename T, qualifier Q>
    GLM_FUNC_QUALIFIER vec<L, T, Q> reciprocal(vec<L, T, Q> const& x)
    {
        GLM_STATIC_ASSERT( std::numeric_limits<T>::is_iec559 || GLM_CONFIG_UNRESTRICTED_FLOAT, 
                           "'reciprocal' only accept floating-point inputs" );
    
        return detail::compute_reciprocal<L, T, Q, detail::is_aligned<Q>::value>::call(x);
    }

}//namespace glm

#if GLM_CONFIG_SIMD == GLM_ENABLE
#	include "navie_reciprocal_simd.inl"
#endif
