;; Auto-generated. Do not edit!


(when (boundp 'darknet_ros::bbox)
  (if (not (find-package "DARKNET_ROS"))
    (make-package "DARKNET_ROS"))
  (shadow 'bbox (find-package "DARKNET_ROS")))
(unless (find-package "DARKNET_ROS::BBOX")
  (make-package "DARKNET_ROS::BBOX"))

(in-package "ROS")
;;//! \htmlinclude bbox.msg.html


(defclass darknet_ros::bbox
  :super ros::object
  :slots (_Class _prob _xmin _ymin _xmax _ymax ))

(defmethod darknet_ros::bbox
  (:init
   (&key
    ((:Class __Class) "")
    ((:prob __prob) 0.0)
    ((:xmin __xmin) 0)
    ((:ymin __ymin) 0)
    ((:xmax __xmax) 0)
    ((:ymax __ymax) 0)
    )
   (send-super :init)
   (setq _Class (string __Class))
   (setq _prob (float __prob))
   (setq _xmin (round __xmin))
   (setq _ymin (round __ymin))
   (setq _xmax (round __xmax))
   (setq _ymax (round __ymax))
   self)
  (:Class
   (&optional __Class)
   (if __Class (setq _Class __Class)) _Class)
  (:prob
   (&optional __prob)
   (if __prob (setq _prob __prob)) _prob)
  (:xmin
   (&optional __xmin)
   (if __xmin (setq _xmin __xmin)) _xmin)
  (:ymin
   (&optional __ymin)
   (if __ymin (setq _ymin __ymin)) _ymin)
  (:xmax
   (&optional __xmax)
   (if __xmax (setq _xmax __xmax)) _xmax)
  (:ymax
   (&optional __ymax)
   (if __ymax (setq _ymax __ymax)) _ymax)
  (:serialization-length
   ()
   (+
    ;; string _Class
    4 (length _Class)
    ;; float32 _prob
    4
    ;; uint32 _xmin
    4
    ;; uint32 _ymin
    4
    ;; uint32 _xmax
    4
    ;; uint32 _ymax
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _Class
       (write-long (length _Class) s) (princ _Class s)
     ;; float32 _prob
       (sys::poke _prob (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; uint32 _xmin
       (write-long _xmin s)
     ;; uint32 _ymin
       (write-long _ymin s)
     ;; uint32 _xmax
       (write-long _xmax s)
     ;; uint32 _ymax
       (write-long _ymax s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _Class
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _Class (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; float32 _prob
     (setq _prob (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; uint32 _xmin
     (setq _xmin (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _ymin
     (setq _ymin (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _xmax
     (setq _xmax (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _ymax
     (setq _ymax (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get darknet_ros::bbox :md5sum-) "00e2c31f0d52d092f799864f91687833")
(setf (get darknet_ros::bbox :datatype-) "darknet_ros/bbox")
(setf (get darknet_ros::bbox :definition-)
      "string Class
float32 prob
uint32 xmin
uint32 ymin
uint32 xmax
uint32 ymax

")



(provide :darknet_ros/bbox "00e2c31f0d52d092f799864f91687833")


