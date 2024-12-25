/// @ref ext2_minmax

#include "../detail/_vectorize2.hpp"

#if GLM_HAS_CXX11_STL
#   include <algorithm> // for std::minmax
#endif


namespace glm
{

	// minmax
#	if GLM_HAS_CXX11_STL
	    template<typename genType>
	    GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::pair<genType, genType> minmax(genType x, genType y)
	    {
	    	return std::minmax<typename std::decay<genType>::type>(x, y);
	    }
        
	    template<typename genType>
	    GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::pair<genType, genType> minmax(genType x, genType y, genType z)
	    {
	    	return std::minmax<typename std::decay<genType>::type>({ x, y, z });
	    }
        
	    template<typename genType>
	    GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::pair<genType, genType> minmax(genType x, genType y, genType z, genType w)
	    {
	    	return std::minmax<typename std::decay<genType>::type>({ x, y, z, w });
	    }
#   else
	    template<typename genType>
	    GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::pair<genType, genType> minmax(genType x, genType y)
	    {
	    	GLM_STATIC_ASSERT(std::numeric_limits<genType>::is_iec559 || GLM_CONFIG_UNRESTRICTED_FLOAT || std::numeric_limits<genType>::is_integer, "'minmax' only accept floating-point or integer inputs");
	    	return (y < x) ? std::make_pair<genType, genType>(y, x) : std::make_pair<genType, genType>(x, y);
	    }
        
	    template<typename genType>
	    GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::pair<genType, genType> minmax(genType x, genType y, genType z)
	    {
	    	GLM_STATIC_ASSERT(std::numeric_limits<genType>::is_iec559 || GLM_CONFIG_UNRESTRICTED_FLOAT || std::numeric_limits<genType>::is_integer, "'minmax' only accept floating-point or integer inputs");
            genType Valmin, Valmax;
            std::tie(Valmin, Valmax) = glm::minmax(x, y);
	    	return std::make_pair<genType, genType>(glm::min(Valmin, z), glm::max(Valmax, z));
	    }
        
	    template<typename genType>
	    GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::pair<genType, genType> minmax(genType x, genType y, genType z, genType w)
	    {
	    	GLM_STATIC_ASSERT(std::numeric_limits<genType>::is_iec559 || GLM_CONFIG_UNRESTRICTED_FLOAT || std::numeric_limits<genType>::is_integer, "'minmax' only accept floating-point or integer inputs");
            genType Valmin0, Valmin1, Valmax0, Valmax1;
            std::tie(Valmin0, Valmax0) = glm::minmax(x, y);
            std::tie(Valmin1, Valmax1) = glm::minmax(z, w);
	    	return std::make_pair<genType, genType>(glm::min(Valmin0, Valmin1), glm::max(Valmax0, Valmax1));
	    }
#   endif

	template<typename T>
	struct TMinmax {
		std::pair<T, T> operator()(const T& a, const T& b) { return minmax(a, b); }
        
		std::pair<T, T> operator()(const T& a, const T& b, const T& c) { return minmax(a, b, c); }
    
		std::pair<T, T> operator()(const T& a, const T& b, const T& c, const T& d) { return minmax(a, b, c, d); }
	};

}//namespace glm


namespace glm{
namespace detail
{

	template<length_t L, typename T, qualifier Q, bool Aligned>
	struct compute_minmax_vector
	{
		GLM_FUNC_QUALIFIER static std::pair<vec<L, T, Q>, vec<L, T, Q>> call(vec<L, T, Q> const& x, vec<L, T, Q> const& y)
		{
			return detail::functor2<vec, L, T, Q>::call(TMinmax<T>(), x, y);
		}
        
		GLM_FUNC_QUALIFIER static std::pair<vec<L, T, Q>, vec<L, T, Q>> call(vec<L, T, Q> const& x, vec<L, T, Q> const& y, vec<L, T, Q> const& z)
		{
			return detail::functor3<vec, L, T, Q>::call(TMinmax<T>(), x, y, z);
		}
        
        
		GLM_FUNC_QUALIFIER static std::pair<vec<L, T, Q>, vec<L, T, Q>> call(vec<L, T, Q> const& x, vec<L, T, Q> const& y, vec<L, T, Q> const& z, vec<L, T, Q> const& w)
		{
			return detail::functor4<vec, L, T, Q>::call(TMinmax<T>(), x, y, z, w);
		}
	};

}//namespace detail

	// minmax
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::pair<vec<L, T, Q>, vec<L, T, Q>> minmax(vec<L, T, Q> const& a, T b)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559 || GLM_CONFIG_UNRESTRICTED_FLOAT || std::numeric_limits<T>::is_integer, "'minmax' only accept floating-point or integer inputs");
		return detail::compute_minmax_vector<L, T, Q, detail::is_aligned<Q>::value>::call(a, vec<L, T, Q>(b));
	}
    
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::pair<vec<L, T, Q>, vec<L, T, Q>> minmax(T a, vec<L, T, Q> const& b)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559 || GLM_CONFIG_UNRESTRICTED_FLOAT || std::numeric_limits<T>::is_integer, "'minmax' only accept floating-point or integer inputs");
		return detail::compute_minmax_vector<L, T, Q, detail::is_aligned<Q>::value>::call(vec<L, T, Q>(a), b);
	}

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::pair<vec<L, T, Q>, vec<L, T, Q>> minmax(vec<L, T, Q> const& a, vec<L, T, Q> const& b)
	{
		return detail::compute_minmax_vector<L, T, Q, detail::is_aligned<Q>::value>::call(a, b);
	}

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::pair<vec<L, T, Q>, vec<L, T, Q>> minmax(vec<L, T, Q> const& a, vec<L, T, Q> const& b, vec<L, T, Q> const& c)
	{
		return detail::compute_minmax_vector<L, T, Q, detail::is_aligned<Q>::value>::call(a, b, c);
	}

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::pair<vec<L, T, Q>, vec<L, T, Q>> minmax(vec<L, T, Q> const& a, vec<L, T, Q> const& b, vec<L, T, Q> const& c, vec<L, T, Q> const& d)
	{
		return detail::compute_minmax_vector<L, T, Q, detail::is_aligned<Q>::value>::call(a, b, c, d);
	}

}//namespace glm
