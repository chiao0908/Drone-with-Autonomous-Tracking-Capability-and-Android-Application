;; Auto-generated. Do not edit!


(when (boundp 'darknet_ros::bbox_array)
  (if (not (find-package "DARKNET_ROS"))
    (make-package "DARKNET_ROS"))
  (shadow 'bbox_array (find-package "DARKNET_ROS")))
(unless (find-package "DARKNET_ROS::BBOX_ARRAY")
  (make-package "DARKNET_ROS::BBOX_ARRAY"))

(in-package "ROS")
;;//! \htmlinclude bbox_array.msg.html


(defclass darknet_ros::bbox_array
  :super ros::object
  :slots (_bboxes ))

(defmethod darknet_ros::bbox_array
  (:init
   (&key
    ((:bboxes __bboxes) (let (r) (dotimes (i 0) (push (instance darknet_ros::bbox :init) r)) r))
    )
   (send-super :init)
   (setq _bboxes __bboxes)
   self)
  (:bboxes
   (&rest __bboxes)
   (if (keywordp (car __bboxes))
       (send* _bboxes __bboxes)
     (progn
       (if __bboxes (setq _bboxes (car __bboxes)))
       _bboxes)))
  (:serialization-length
   ()
   (+
    ;; darknet_ros/bbox[] _bboxes
    (apply #'+ (send-all _bboxes :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; darknet_ros/bbox[] _bboxes
     (write-long (length _bboxes) s)
     (dolist (elem _bboxes)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; darknet_ros/bbox[] _bboxes
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _bboxes (let (r) (dotimes (i n) (push (instance darknet_ros::bbox :init) r)) r))
     (dolist (elem- _bboxes)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get darknet_ros::bbox_array :md5sum-) "2007cc1ade1d04841511e0551e2afc0a")
(setf (get darknet_ros::bbox_array :datatype-) "darknet_ros/bbox_array")
(setf (get darknet_ros::bbox_array :definition-)
      "bbox[] bboxes

================================================================================
MSG: darknet_ros/bbox
string Class
float32 prob
uint32 xmin
uint32 ymin
uint32 xmax
uint32 ymax

")



(provide :darknet_ros/bbox_array "2007cc1ade1d04841511e0551e2afc0a")


