#include<vector>

#include<boost/shared_ptr.hpp>

#include<CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include<CGAL/Polygon_2.h>
#include<CGAL/create_offset_polygons_2.h>

#include "print.h" 

typedef CGAL::Exact_predicates_inexact_constructions_kernel K ;

typedef K::Point_2                   Point ;
typedef CGAL::Polygon_2<K>           Polygon ;
typedef CGAL::Straight_skeleton_2<K> Ss ;

typedef boost::shared_ptr<Polygon> PolygonPtr ;
typedef boost::shared_ptr<Ss> SsPtr ;

typedef std::vector<PolygonPtr> PolygonPtrVector ;

int main()
{
  Polygon poly ;
  
  poly.push_back( Point(-1,-1) ) ;
  poly.push_back( Point(0,-12) ) ;
  poly.push_back( Point(1,-1) ) ;
  poly.push_back( Point(12,0) ) ;
  poly.push_back( Point(1,1) ) ;
  poly.push_back( Point(0,12) ) ;
  poly.push_back( Point(-1,1) ) ;
  poly.push_back( Point(-12,0) ) ;
     
  SsPtr ss = CGAL::create_interior_straight_skeleton_2(poly);
  
  double lOffset = 1 ;
  
  PolygonPtrVector offset_polygons = CGAL::create_offset_polygons_2<Polygon>(lOffset,*ss);
  
  print_polygons(offset_polygons);
  
  return 0;
}
