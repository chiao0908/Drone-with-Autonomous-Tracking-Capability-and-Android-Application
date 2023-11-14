; Auto-generated. Do not edit!


(cl:in-package darknet_ros-msg)


;//! \htmlinclude bbox.msg.html

(cl:defclass <bbox> (roslisp-msg-protocol:ros-message)
  ((Class
    :reader Class
    :initarg :Class
    :type cl:string
    :initform "")
   (prob
    :reader prob
    :initarg :prob
    :type cl:float
    :initform 0.0)
   (xmin
    :reader xmin
    :initarg :xmin
    :type cl:integer
    :initform 0)
   (ymin
    :reader ymin
    :initarg :ymin
    :type cl:integer
    :initform 0)
   (xmax
    :reader xmax
    :initarg :xmax
    :type cl:integer
    :initform 0)
   (ymax
    :reader ymax
    :initarg :ymax
    :type cl:integer
    :initform 0))
)

(cl:defclass bbox (<bbox>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <bbox>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'bbox)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name darknet_ros-msg:<bbox> is deprecated: use darknet_ros-msg:bbox instead.")))

(cl:ensure-generic-function 'Class-val :lambda-list '(m))
(cl:defmethod Class-val ((m <bbox>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader darknet_ros-msg:Class-val is deprecated.  Use darknet_ros-msg:Class instead.")
  (Class m))

(cl:ensure-generic-function 'prob-val :lambda-list '(m))
(cl:defmethod prob-val ((m <bbox>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader darknet_ros-msg:prob-val is deprecated.  Use darknet_ros-msg:prob instead.")
  (prob m))

(cl:ensure-generic-function 'xmin-val :lambda-list '(m))
(cl:defmethod xmin-val ((m <bbox>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader darknet_ros-msg:xmin-val is deprecated.  Use darknet_ros-msg:xmin instead.")
  (xmin m))

(cl:ensure-generic-function 'ymin-val :lambda-list '(m))
(cl:defmethod ymin-val ((m <bbox>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader darknet_ros-msg:ymin-val is deprecated.  Use darknet_ros-msg:ymin instead.")
  (ymin m))

(cl:ensure-generic-function 'xmax-val :lambda-list '(m))
(cl:defmethod xmax-val ((m <bbox>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader darknet_ros-msg:xmax-val is deprecated.  Use darknet_ros-msg:xmax instead.")
  (xmax m))

(cl:ensure-generic-function 'ymax-val :lambda-list '(m))
(cl:defmethod ymax-val ((m <bbox>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader darknet_ros-msg:ymax-val is deprecated.  Use darknet_ros-msg:ymax instead.")
  (ymax m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <bbox>) ostream)
  "Serializes a message object of type '<bbox>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'Class))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'Class))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'prob))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'xmin)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'xmin)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'xmin)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'xmin)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'ymin)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'ymin)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'ymin)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'ymin)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'xmax)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'xmax)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'xmax)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'xmax)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'ymax)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'ymax)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'ymax)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'ymax)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <bbox>) istream)
  "Deserializes a message object of type '<bbox>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'Class) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'Class) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'prob) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'xmin)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'xmin)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'xmin)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'xmin)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'ymin)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'ymin)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'ymin)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'ymin)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'xmax)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'xmax)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'xmax)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'xmax)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'ymax)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'ymax)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'ymax)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'ymax)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<bbox>)))
  "Returns string type for a message object of type '<bbox>"
  "darknet_ros/bbox")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'bbox)))
  "Returns string type for a message object of type 'bbox"
  "darknet_ros/bbox")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<bbox>)))
  "Returns md5sum for a message object of type '<bbox>"
  "00e2c31f0d52d092f799864f91687833")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'bbox)))
  "Returns md5sum for a message object of type 'bbox"
  "00e2c31f0d52d092f799864f91687833")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<bbox>)))
  "Returns full string definition for message of type '<bbox>"
  (cl:format cl:nil "string Class~%float32 prob~%uint32 xmin~%uint32 ymin~%uint32 xmax~%uint32 ymax~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'bbox)))
  "Returns full string definition for message of type 'bbox"
  (cl:format cl:nil "string Class~%float32 prob~%uint32 xmin~%uint32 ymin~%uint32 xmax~%uint32 ymax~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <bbox>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'Class))
     4
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <bbox>))
  "Converts a ROS message object to a list"
  (cl:list 'bbox
    (cl:cons ':Class (Class msg))
    (cl:cons ':prob (prob msg))
    (cl:cons ':xmin (xmin msg))
    (cl:cons ':ymin (ymin msg))
    (cl:cons ':xmax (xmax msg))
    (cl:cons ':ymax (ymax msg))
))
