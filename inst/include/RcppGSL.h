// RcppGSL.h: Rcpp/GSL glue
//
// Copyright (C)  2010 Romain Francois and Dirk Eddelbuettel
//
// This file is part of RcppGSL.
//
// RcppGSL is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//                           
// RcppGSL is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with RcppGSL.  If not, see <http://www.gnu.org/licenses/>.

#ifndef RCPPGSL__RCPPGSL_H
#define RCPPGSL__RCPPGSL_H

#include <RcppGSLForward.h>
#include <Rcpp.h>

namespace Rcpp{
	
	namespace internal{
		template<> gsl_complex caster<Rcomplex,gsl_complex>( Rcomplex from){
			gsl_complex x ;
			GSL_REAL(x) = from.r ;
			GSL_IMAG(x) = from.i ;
			return x ;
		}
		template<> Rcomplex caster<gsl_complex,Rcomplex>( gsl_complex from){
			Rcomplex x ;
			x.r = GSL_REAL(from) ;
			x.i = GSL_IMAG(from) ;
			return x ;
		}
		
		template<> gsl_complex_float caster<Rcomplex,gsl_complex_float>( Rcomplex from){
			gsl_complex_float x ;
			GSL_REAL(x) = static_cast<float>( from.r ) ;
			GSL_IMAG(x) = static_cast<float>( from.i ) ;
			return x ;
		}
		template<> Rcomplex caster<gsl_complex_float,Rcomplex>( gsl_complex_float from){
			Rcomplex x ;
			x.r = static_cast<double>( GSL_REAL(from) ) ;
			x.i = static_cast<double>( GSL_IMAG(from) ) ;
			return x ;
		}
	
		template<> gsl_complex_long_double caster<Rcomplex,gsl_complex_long_double>( Rcomplex from){
			gsl_complex_long_double x ;
			GSL_REAL(x) = static_cast<float>( from.r ) ;
			GSL_IMAG(x) = static_cast<float>( from.i ) ;
			return x ;
		}
		template<> Rcomplex caster<gsl_complex_long_double,Rcomplex>( gsl_complex_long_double from){
			Rcomplex x ;
			x.r = static_cast<double>( GSL_REAL(from) ) ;
			x.i = static_cast<double>( GSL_IMAG(from) ) ;
			return x ;
		}
	}

template <> SEXP wrap( const gsl_vector& x){
	return wrap( x.data, x.data + x.size ) ;
}

template <> SEXP wrap( const gsl_vector_float& x){
	return wrap( x.data, x.data + x.size ) ;
}

template <> SEXP wrap( const gsl_vector_int& x){
	return wrap( x.data, x.data + x.size ) ;
}

template <> SEXP wrap( const gsl_vector_long& x){
	return wrap( x.data, x.data + x.size ) ;
}

template <> SEXP wrap( const gsl_vector_char& x){
	return wrap( 
		reinterpret_cast<Rbyte* const>(x.data), 
		reinterpret_cast<Rbyte* const>(x.data) + x.size ) ;	
}

template <> SEXP wrap( const gsl_vector_complex& x){
	return wrap(
		reinterpret_cast<gsl_complex*>(x.data), 
		reinterpret_cast<gsl_complex*>(x.data) + x.size ) ;	
}
 
template <> SEXP wrap( const gsl_vector_complex_float& x){
	return wrap( 
		reinterpret_cast<gsl_complex_float*>(x.data), 
		reinterpret_cast<gsl_complex_float*>(x.data) + x.size ) ;	
}

template <> SEXP wrap( const gsl_vector_complex_long_double& x){
	return wrap( 
		reinterpret_cast<gsl_complex_long_double*>(x.data), 
		reinterpret_cast<gsl_complex_long_double*>(x.data) + x.size ) ;	
}

template <> SEXP wrap( const gsl_vector_long_double& x){
	return wrap( x.data, x.data + x.size ) ;
}

template <> SEXP wrap( const gsl_vector_short& x){
	return wrap( x.data, x.data + x.size ) ;
}

template <> SEXP wrap( const gsl_vector_uchar& x){
	return wrap( x.data, x.data + x.size ) ;
}

template <> SEXP wrap( const gsl_vector_uint& x){
	return wrap( x.data, x.data + x.size ) ;
}

template <> SEXP wrap( const gsl_vector_ushort& x){
	return wrap( x.data, x.data + x.size ) ;
}

template <> SEXP wrap( const gsl_vector_ulong& x){
	return wrap( x.data, x.data + x.size ) ;
}


/* matrices */

template <> SEXP wrap( const gsl_matrix& x){
	return internal::rowmajor_wrap( x.data, x.size1, x.size2 ) ;
}


} 

#endif
