// Auto-generated. Do not edit!

// (in-package darknet_ros.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let bbox = require('./bbox.js');

//-----------------------------------------------------------

class bbox_array {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.bboxes = null;
    }
    else {
      if (initObj.hasOwnProperty('bboxes')) {
        this.bboxes = initObj.bboxes
      }
      else {
        this.bboxes = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type bbox_array
    // Serialize message field [bboxes]
    // Serialize the length for message field [bboxes]
    bufferOffset = _serializer.uint32(obj.bboxes.length, buffer, bufferOffset);
    obj.bboxes.forEach((val) => {
      bufferOffset = bbox.serialize(val, buffer, bufferOffset);
    });
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type bbox_array
    let len;
    let data = new bbox_array(null);
    // Deserialize message field [bboxes]
    // Deserialize array length for message field [bboxes]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.bboxes = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.bboxes[i] = bbox.deserialize(buffer, bufferOffset)
    }
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    object.bboxes.forEach((val) => {
      length += bbox.getMessageSize(val);
    });
    return length + 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'darknet_ros/bbox_array';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '2007cc1ade1d04841511e0551e2afc0a';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bbox[] bboxes
    
    ================================================================================
    MSG: darknet_ros/bbox
    string Class
    float32 prob
    uint32 xmin
    uint32 ymin
    uint32 xmax
    uint32 ymax
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new bbox_array(null);
    if (msg.bboxes !== undefined) {
      resolved.bboxes = new Array(msg.bboxes.length);
      for (let i = 0; i < resolved.bboxes.length; ++i) {
        resolved.bboxes[i] = bbox.Resolve(msg.bboxes[i]);
      }
    }
    else {
      resolved.bboxes = []
    }

    return resolved;
    }
};

module.exports = bbox_array;
