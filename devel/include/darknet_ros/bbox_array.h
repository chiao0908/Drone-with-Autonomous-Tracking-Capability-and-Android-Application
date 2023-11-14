// Generated by gencpp from file darknet_ros/bbox_array.msg
// DO NOT EDIT!


#ifndef DARKNET_ROS_MESSAGE_BBOX_ARRAY_H
#define DARKNET_ROS_MESSAGE_BBOX_ARRAY_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <darknet_ros/bbox.h>

namespace darknet_ros
{
template <class ContainerAllocator>
struct bbox_array_
{
  typedef bbox_array_<ContainerAllocator> Type;

  bbox_array_()
    : bboxes()  {
    }
  bbox_array_(const ContainerAllocator& _alloc)
    : bboxes(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector< ::darknet_ros::bbox_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::darknet_ros::bbox_<ContainerAllocator> >::other >  _bboxes_type;
  _bboxes_type bboxes;





  typedef boost::shared_ptr< ::darknet_ros::bbox_array_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::darknet_ros::bbox_array_<ContainerAllocator> const> ConstPtr;

}; // struct bbox_array_

typedef ::darknet_ros::bbox_array_<std::allocator<void> > bbox_array;

typedef boost::shared_ptr< ::darknet_ros::bbox_array > bbox_arrayPtr;
typedef boost::shared_ptr< ::darknet_ros::bbox_array const> bbox_arrayConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::darknet_ros::bbox_array_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::darknet_ros::bbox_array_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace darknet_ros

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'darknet_ros': ['/home/nvidia/ros_catkin_ws/src/darknet_ros/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::darknet_ros::bbox_array_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::darknet_ros::bbox_array_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::darknet_ros::bbox_array_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::darknet_ros::bbox_array_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::darknet_ros::bbox_array_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::darknet_ros::bbox_array_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::darknet_ros::bbox_array_<ContainerAllocator> >
{
  static const char* value()
  {
    return "2007cc1ade1d04841511e0551e2afc0a";
  }

  static const char* value(const ::darknet_ros::bbox_array_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x2007cc1ade1d0484ULL;
  static const uint64_t static_value2 = 0x1511e0551e2afc0aULL;
};

template<class ContainerAllocator>
struct DataType< ::darknet_ros::bbox_array_<ContainerAllocator> >
{
  static const char* value()
  {
    return "darknet_ros/bbox_array";
  }

  static const char* value(const ::darknet_ros::bbox_array_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::darknet_ros::bbox_array_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bbox[] bboxes\n\
\n\
================================================================================\n\
MSG: darknet_ros/bbox\n\
string Class\n\
float32 prob\n\
uint32 xmin\n\
uint32 ymin\n\
uint32 xmax\n\
uint32 ymax\n\
";
  }

  static const char* value(const ::darknet_ros::bbox_array_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::darknet_ros::bbox_array_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.bboxes);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct bbox_array_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::darknet_ros::bbox_array_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::darknet_ros::bbox_array_<ContainerAllocator>& v)
  {
    s << indent << "bboxes[]" << std::endl;
    for (size_t i = 0; i < v.bboxes.size(); ++i)
    {
      s << indent << "  bboxes[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::darknet_ros::bbox_<ContainerAllocator> >::stream(s, indent + "    ", v.bboxes[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // DARKNET_ROS_MESSAGE_BBOX_ARRAY_H
