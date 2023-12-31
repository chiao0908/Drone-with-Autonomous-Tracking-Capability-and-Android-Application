# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from darknet_ros/bbox_array.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import darknet_ros.msg

class bbox_array(genpy.Message):
  _md5sum = "2007cc1ade1d04841511e0551e2afc0a"
  _type = "darknet_ros/bbox_array"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """bbox[] bboxes

================================================================================
MSG: darknet_ros/bbox
string Class
float32 prob
uint32 xmin
uint32 ymin
uint32 xmax
uint32 ymax
"""
  __slots__ = ['bboxes']
  _slot_types = ['darknet_ros/bbox[]']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       bboxes

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(bbox_array, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.bboxes is None:
        self.bboxes = []
    else:
      self.bboxes = []

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      length = len(self.bboxes)
      buff.write(_struct_I.pack(length))
      for val1 in self.bboxes:
        _x = val1.Class
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        _x = val1
        buff.write(_get_struct_f4I().pack(_x.prob, _x.xmin, _x.ymin, _x.xmax, _x.ymax))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.bboxes is None:
        self.bboxes = None
      end = 0
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.bboxes = []
      for i in range(0, length):
        val1 = darknet_ros.msg.bbox()
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.Class = str[start:end].decode('utf-8')
        else:
          val1.Class = str[start:end]
        _x = val1
        start = end
        end += 20
        (_x.prob, _x.xmin, _x.ymin, _x.xmax, _x.ymax,) = _get_struct_f4I().unpack(str[start:end])
        self.bboxes.append(val1)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      length = len(self.bboxes)
      buff.write(_struct_I.pack(length))
      for val1 in self.bboxes:
        _x = val1.Class
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        _x = val1
        buff.write(_get_struct_f4I().pack(_x.prob, _x.xmin, _x.ymin, _x.xmax, _x.ymax))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.bboxes is None:
        self.bboxes = None
      end = 0
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.bboxes = []
      for i in range(0, length):
        val1 = darknet_ros.msg.bbox()
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.Class = str[start:end].decode('utf-8')
        else:
          val1.Class = str[start:end]
        _x = val1
        start = end
        end += 20
        (_x.prob, _x.xmin, _x.ymin, _x.xmax, _x.ymax,) = _get_struct_f4I().unpack(str[start:end])
        self.bboxes.append(val1)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_f4I = None
def _get_struct_f4I():
    global _struct_f4I
    if _struct_f4I is None:
        _struct_f4I = struct.Struct("<f4I")
    return _struct_f4I
